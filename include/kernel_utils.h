#ifndef KERNEL_UTILS_H
#define KERNEL_UTILS_H

#include "fw_defines.h"
#include "ps4.h"

#ifdef printf_notification
#undef printf_notification
#endif

#define printf_notification(...)                       \
  do {                                                 \
    char message[256];                                 \
    snprintf(message, sizeof(message), ##__VA_ARGS__); \
    systemMessage(message);                            \
  } while (0)

struct kpayload_get_fw_version_info {
  uint64_t uaddr;
};

struct kpayload_get_fw_version_args {
  void *syscall_handler;
  struct kpayload_get_fw_version_info *kpayload_get_fw_version_info;
};

struct kpayload_jailbreak_info {
  uint64_t fw_version;
};

struct kpayload_jailbreak_args {
  void *syscall_handler;
  struct kpayload_jailbreak_info *kpayload_jailbreak_info;
};


uint64_t get_fw_version(void);
int jailbreak(uint64_t fw_version);

#endif
