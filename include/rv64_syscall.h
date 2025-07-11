#define RV64_SYS_io_setup 0
#define RV64_SYS_io_destroy 1
#define RV64_SYS_io_submit 2
#define RV64_SYS_io_cancel 3
#define RV64_SYS_io_getevents 4
#define RV64_SYS_setxattr 5
#define RV64_SYS_lsetxattr 6
#define RV64_SYS_fsetxattr 7
#define RV64_SYS_getxattr 8
#define RV64_SYS_lgetxattr 9
#define RV64_SYS_fgetxattr 10
#define RV64_SYS_listxattr 11
#define RV64_SYS_llistxattr 12
#define RV64_SYS_flistxattr 13
#define RV64_SYS_removexattr 14
#define RV64_SYS_lremovexattr 15
#define RV64_SYS_fremovexattr 16
#define RV64_SYS_getcwd 17
#define RV64_SYS_lookup_dcookie 18
#define RV64_SYS_eventfd2 19
#define RV64_SYS_epoll_create1 20
#define RV64_SYS_epoll_ctl 21
#define RV64_SYS_epoll_pwait 22
#define RV64_SYS_dup 23
#define RV64_SYS_dup3 24
#define RV64_SYS_fcntl 25
#define RV64_SYS_inotify_init1 26
#define RV64_SYS_inotify_add_watch 27
#define RV64_SYS_inotify_rm_watch 28
#define RV64_SYS_ioctl 29
#define RV64_SYS_ioprio_set 30
#define RV64_SYS_ioprio_get 31
#define RV64_SYS_flock 32
#define RV64_SYS_mknodat 33
#define RV64_SYS_mkdirat 34
#define RV64_SYS_unlinkat 35
#define RV64_SYS_symlinkat 36
#define RV64_SYS_linkat 37
#define RV64_SYS_renameat 38
#define RV64_SYS_umount2 39
#define RV64_SYS_mount 40
#define RV64_SYS_pivot_root 41
#define RV64_SYS_nfsservctl 42
#define RV64_SYS_statfs 43
#define RV64_SYS_fstatfs 44
#define RV64_SYS_truncate 45
#define RV64_SYS_ftruncate 46
#define RV64_SYS_fallocate 47
#define RV64_SYS_faccessat 48
#define RV64_SYS_chdir 49
#define RV64_SYS_fchdir 50
#define RV64_SYS_chroot 51
#define RV64_SYS_fchmod 52
#define RV64_SYS_fchmodat 53
#define RV64_SYS_fchownat 54
#define RV64_SYS_fchown 55
#define RV64_SYS_openat 56
#define RV64_SYS_close 57
#define RV64_SYS_vhangup 58
#define RV64_SYS_pipe2 59
#define RV64_SYS_quotactl 60
#define RV64_SYS_getdents64 61
#define RV64_SYS_lseek 62
#define RV64_SYS_read 63
#define RV64_SYS_write 64
#define RV64_SYS_readv 65
#define RV64_SYS_writev 66
#define RV64_SYS_pread64 67
#define RV64_SYS_pwrite64 68
#define RV64_SYS_preadv 69
#define RV64_SYS_pwritev 70
#define RV64_SYS_sendfile 71
#define RV64_SYS_pselect6 72
#define RV64_SYS_ppoll 73
#define RV64_SYS_signalfd4 74
#define RV64_SYS_vmsplice 75
#define RV64_SYS_splice 76
#define RV64_SYS_tee 77
#define RV64_SYS_readlinkat 78
#define RV64_SYS_fstatat 79
#define RV64_SYS_fstat 80
#define RV64_SYS_sync 81
#define RV64_SYS_fsync 82
#define RV64_SYS_fdatasync 83
#define RV64_SYS_sync_file_range2 84
#define RV64_SYS_sync_file_range 84
#define RV64_SYS_timerfd_create 85
#define RV64_SYS_timerfd_settime 86
#define RV64_SYS_timerfd_gettime 87
#define RV64_SYS_utimensat 88
#define RV64_SYS_acct 89
#define RV64_SYS_capget 90
#define RV64_SYS_capset 91
#define RV64_SYS_personality 92
#define RV64_SYS_exit 93
#define RV64_SYS_exit_group 94
#define RV64_SYS_waitid 95
#define RV64_SYS_set_tid_address 96
#define RV64_SYS_unshare 97
#define RV64_SYS_futex 98
#define RV64_SYS_set_robust_list 99
#define RV64_SYS_get_robust_list 100
#define RV64_SYS_nanosleep 101
#define RV64_SYS_getitimer 102
#define RV64_SYS_setitimer 103
#define RV64_SYS_kexec_load 104
#define RV64_SYS_init_module 105
#define RV64_SYS_delete_module 106
#define RV64_SYS_timer_create 107
#define RV64_SYS_timer_gettime 108
#define RV64_SYS_timer_getoverrun 109
#define RV64_SYS_timer_settime 110
#define RV64_SYS_timer_delete 111
#define RV64_SYS_clock_settime 112
#define RV64_SYS_clock_gettime 113
#define RV64_SYS_clock_getres 114
#define RV64_SYS_clock_nanosleep 115
#define RV64_SYS_syslog 116
#define RV64_SYS_ptrace 117
#define RV64_SYS_sched_setparam 118
#define RV64_SYS_sched_setscheduler 119
#define RV64_SYS_sched_getscheduler 120
#define RV64_SYS_sched_getparam 121
#define RV64_SYS_sched_setaffinity 122
#define RV64_SYS_sched_getaffinity 123
#define RV64_SYS_sched_yield 124
#define RV64_SYS_sched_get_priority_max 125
#define RV64_SYS_sched_get_priority_min 126
#define RV64_SYS_sched_rr_get_interval 127
#define RV64_SYS_restart_syscall 128
#define RV64_SYS_kill 129
#define RV64_SYS_tkill 130
#define RV64_SYS_tgkill 131
#define RV64_SYS_sigaltstack 132
#define RV64_SYS_rt_sigsuspend 133
#define RV64_SYS_rt_sigaction 134
#define RV64_SYS_rt_sigprocmask 135
#define RV64_SYS_rt_sigpending 136
#define RV64_SYS_rt_sigtimedwait 137
#define RV64_SYS_rt_sigqueueinfo 138
#define RV64_SYS_rt_sigreturn 139
#define RV64_SYS_setpriority 140
#define RV64_SYS_getpriority 141
#define RV64_SYS_reboot 142
#define RV64_SYS_setregid 143
#define RV64_SYS_setgid 144
#define RV64_SYS_setreuid 145
#define RV64_SYS_setuid 146
#define RV64_SYS_setresuid 147
#define RV64_SYS_getresuid 148
#define RV64_SYS_setresgid 149
#define RV64_SYS_getresgid 150
#define RV64_SYS_setfsuid 151
#define RV64_SYS_setfsgid 152
#define RV64_SYS_times 153
#define RV64_SYS_setpgid 154
#define RV64_SYS_getpgid 155
#define RV64_SYS_getsid 156
#define RV64_SYS_setsid 157
#define RV64_SYS_getgroups 158
#define RV64_SYS_setgroups 159
#define RV64_SYS_uname 160
#define RV64_SYS_sethostname 161
#define RV64_SYS_setdomainname 162
#define RV64_SYS_getrlimit 163
#define RV64_SYS_setrlimit 164
#define RV64_SYS_getrusage 165
#define RV64_SYS_umask 166
#define RV64_SYS_prctl 167
#define RV64_SYS_getcpu 168
#define RV64_SYS_gettimeofday 169
#define RV64_SYS_settimeofday 170
#define RV64_SYS_adjtimex 171
#define RV64_SYS_getpid 172
#define RV64_SYS_getppid 173
#define RV64_SYS_getuid 174
#define RV64_SYS_geteuid 175
#define RV64_SYS_getgid 176
#define RV64_SYS_getegid 177
#define RV64_SYS_gettid 178
#define RV64_SYS_sysinfo 179
#define RV64_SYS_mq_open 180
#define RV64_SYS_mq_unlink 181
#define RV64_SYS_mq_timedsend 182
#define RV64_SYS_mq_timedreceive 183
#define RV64_SYS_mq_notify 184
#define RV64_SYS_mq_getsetattr 185
#define RV64_SYS_msgget 186
#define RV64_SYS_msgctl 187
#define RV64_SYS_msgrcv 188
#define RV64_SYS_msgsnd 189
#define RV64_SYS_semget 190
#define RV64_SYS_semctl 191
#define RV64_SYS_semtimedop 192
#define RV64_SYS_semop 193
#define RV64_SYS_shmget 194
#define RV64_SYS_shmctl 195
#define RV64_SYS_shmat 196
#define RV64_SYS_shmdt 197
#define RV64_SYS_socket 198
#define RV64_SYS_socketpair 199
#define RV64_SYS_bind 200
#define RV64_SYS_listen 201
#define RV64_SYS_accept 202
#define RV64_SYS_connect 203
#define RV64_SYS_getsockname 204
#define RV64_SYS_getpeername 205
#define RV64_SYS_sendto 206
#define RV64_SYS_recvfrom 207
#define RV64_SYS_setsockopt 208
#define RV64_SYS_getsockopt 209
#define RV64_SYS_shutdown 210
#define RV64_SYS_sendmsg 211
#define RV64_SYS_recvmsg 212
#define RV64_SYS_readahead 213
#define RV64_SYS_brk 214
#define RV64_SYS_munmap 215
#define RV64_SYS_mremap 216
#define RV64_SYS_add_key 217
#define RV64_SYS_request_key 218
#define RV64_SYS_keyctl 219
#define RV64_SYS_clone 220
#define RV64_SYS_execve 221
#define RV64_SYS_mmap 222
#define RV64_SYS_fadvise64 223
#define RV64_SYS_swapon 224
#define RV64_SYS_swapoff 225
#define RV64_SYS_mprotect 226
#define RV64_SYS_msync 227
#define RV64_SYS_mlock 228
#define RV64_SYS_munlock 229
#define RV64_SYS_mlockall 230
#define RV64_SYS_munlockall 231
#define RV64_SYS_mincore 232
#define RV64_SYS_madvise 233
#define RV64_SYS_remap_file_pages 234
#define RV64_SYS_mbind 235
#define RV64_SYS_get_mempolicy 236
#define RV64_SYS_set_mempolicy 237
#define RV64_SYS_migrate_pages 238
#define RV64_SYS_move_pages 239
#define RV64_SYS_rt_tgsigqueueinfo 240
#define RV64_SYS_perf_event_open 241
#define RV64_SYS_accept4 242
#define RV64_SYS_recvmmsg 243
#define RV64_SYS_arch_specific_syscall 244
#define RV64_SYS_wait4 260
#define RV64_SYS_prlimit64 261
#define RV64_SYS_fanotify_init 262
#define RV64_SYS_fanotify_mark 263
#define RV64_SYS_name_to_handle_at         264
#define RV64_SYS_open_by_handle_at         265
#define RV64_SYS_clock_adjtime 266
#define RV64_SYS_syncfs 267
#define RV64_SYS_setns 268
#define RV64_SYS_sendmmsg 269
#define RV64_SYS_process_vm_readv 270
#define RV64_SYS_process_vm_writev 271
#define RV64_SYS_kcmp 272
#define RV64_SYS_finit_module 273
#define RV64_SYS_sched_setattr 274
#define RV64_SYS_sched_getattr 275
#define RV64_SYS_renameat2 276
#define RV64_SYS_seccomp 277
#define RV64_SYS_getrandom 278
#define RV64_SYS_memfd_create 279
#define RV64_SYS_bpf 280
#define RV64_SYS_execveat 281
#define RV64_SYS_userfaultfd 282
#define RV64_SYS_membarrier 283
#define RV64_SYS_mlock2 284
#define RV64_SYS_copy_file_range 285
#define RV64_SYS_preadv2 286
#define RV64_SYS_pwritev2 287
#define RV64_SYS_pkey_mprotect 288
#define RV64_SYS_pkey_alloc 289
#define RV64_SYS_pkey_free 290
#define RV64_SYS_statx 291
#define RV64_SYS_io_pgetevents 292
#define RV64_SYS_rseq 293
#define RV64_SYS_kexec_file_load 294
#define RV64_SYS_clock_gettime64 403
#define RV64_SYS_clock_settime64 404
#define RV64_SYS_clock_adjtime64 405
#define RV64_SYS_clock_getres_time64 406
#define RV64_SYS_clock_nanosleep_time64 407
#define RV64_SYS_timer_gettime64 408
#define RV64_SYS_timer_settime64 409
#define RV64_SYS_timerfd_gettime64 410
#define RV64_SYS_timerfd_settime64 411
#define RV64_SYS_utimensat_time64 412
#define RV64_SYS_pselect6_time64 413
#define RV64_SYS_ppoll_time64 414
#define RV64_SYS_io_pgetevents_time64 416
#define RV64_SYS_recvmmsg_time64 417
#define RV64_SYS_mq_timedsend_time64 418
#define RV64_SYS_mq_timedreceive_time64 419
#define RV64_SYS_semtimedop_time64 420
#define RV64_SYS_rt_sigtimedwait_time64 421
#define RV64_SYS_futex_time64 422
#define RV64_SYS_sched_rr_get_interval_time64 423
#define RV64_SYS_pidfd_send_signal 424
#define RV64_SYS_io_uring_setup 425
#define RV64_SYS_io_uring_enter 426
#define RV64_SYS_io_uring_register 427
#define RV64_SYS_open_tree 428
#define RV64_SYS_move_mount 429
#define RV64_SYS_fsopen 430
#define RV64_SYS_fsconfig 431
#define RV64_SYS_fsmount 432
#define RV64_SYS_fspick 433
#define RV64_SYS_pidfd_open 434
#define RV64_SYS_clone3 435
#define RV64_SYS_close_range 436
#define RV64_SYS_openat2 437
#define RV64_SYS_pidfd_getfd 438
#define RV64_SYS_faccessat2 439
#define RV64_SYS_process_madvise 440
#define RV64_SYS_epoll_pwait2 441
#define RV64_SYS_mount_setattr 442
#define RV64_SYS_quotactl_fd 443
#define RV64_SYS_landlock_create_ruleset 444
#define RV64_SYS_landlock_add_rule 445
#define RV64_SYS_landlock_restrict_self 446
#define RV64_SYS_memfd_secret 447
#define RV64_SYS_process_mrelease 448
#define RV64_SYS_futex_waitv 449
#define RV64_SYS_set_mempolicy_home_node 450
#define RV64_SYS_cachestat 451
#define RV64_SYS_fchmodat2 452
#define RV64_SYS_syscalls 453

#define RV64_SYS_riscv_flush_icache (RV64_SYS_arch_specific_syscall+15) 
#define RV64_SYS_riscv_hwprobe (RV64_SYS_arch_specific_syscall+14) 
