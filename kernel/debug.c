#include <stdarg.h>
#include <string.h>
#include <kmsg.h>
#include <aal/debug.h>
#include <aal/lock.h>

struct aal_kmsg_buf kmsg_buf AAL_KMSG_ALIGN;

extern int vsnprintf(char *buf, size_t size, const char *fmt, va_list args);
extern int sprintf(char * buf, const char *fmt, ...);
static aal_spinlock_t kmsg_lock;

/* TODO: lock */
void kputs(char *buf)
{
	int len = strlen(buf);
	unsigned long flags;

	flags = aal_mc_spinlock_lock(&kmsg_lock);

	if (len + kmsg_buf.tail > kmsg_buf.len) {
		kmsg_buf.tail = 0;
	}
	
	strncpy(kmsg_buf.str + kmsg_buf.tail, buf, len);
	kmsg_buf.tail += len;

	aal_mc_spinlock_unlock(&kmsg_lock, flags);
}

#define KPRINTF_LOCAL_BUF_LEN 1024

int kprintf_lock()
{
	return aal_mc_spinlock_lock(&kmsg_lock);
}

void kprintf_unlock(int irqflags)
{
	aal_mc_spinlock_unlock(&kmsg_lock, irqflags);
}

/* Caller must hold kmsg_lock! */
int __kprintf(const char *format, ...)
{
	int len = 0;
	va_list va;
	char buf[KPRINTF_LOCAL_BUF_LEN];

	/* Copy into the local buf */
	va_start(va, format);
	len += vsnprintf(buf + len, KPRINTF_LOCAL_BUF_LEN - len, format, va);
	va_end(va);

	/* Append to kmsg buffer */
	if (kmsg_buf.tail + len > kmsg_buf.len) {
		kmsg_buf.tail = 0;
	}

	memcpy(kmsg_buf.str + kmsg_buf.tail, buf, len);
	kmsg_buf.tail += len;

	return len;
}

int kprintf(const char *format, ...)
{
	int len = 0;
	va_list va;
	unsigned long flags;
	char buf[KPRINTF_LOCAL_BUF_LEN];

	flags = aal_mc_spinlock_lock(&kmsg_lock);

	/* Copy into the local buf */
	va_start(va, format);
	len += vsnprintf(buf + len, KPRINTF_LOCAL_BUF_LEN - len, format, va);
	va_end(va);

	/* Append to kmsg buffer */
	if (kmsg_buf.tail + len > kmsg_buf.len) {
		kmsg_buf.tail = 0;
	}

	memcpy(kmsg_buf.str + kmsg_buf.tail, buf, len);
	kmsg_buf.tail += len;

	aal_mc_spinlock_unlock(&kmsg_lock, flags);

	return len;
}

void kmsg_init(void)
{
	aal_mc_spinlock_init(&kmsg_lock);
	kmsg_buf.tail = 0;
	kmsg_buf.len = sizeof(kmsg_buf.str);
	memset(kmsg_buf.str, 0, kmsg_buf.len);
}
