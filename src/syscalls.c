#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "memory.h"
#include "syscalls.h"


void syscall(uint64_t syscode) {
    switch(syscode) {
        case RV64_SYS_io_setup:
            assert(0 && RV64_SYS_io_setup);
            break;
        case RV64_SYS_io_destroy:
            assert(0 && RV64_SYS_io_destroy);
            break;
        case RV64_SYS_io_submit: 
			assert(0 && RV64_SYS_io_submit);
			break;
        case RV64_SYS_io_cancel: 
			assert(0 && RV64_SYS_io_cancel);
			break;
        case RV64_SYS_io_getevents: 
			assert(0 && RV64_SYS_io_getevents);
			break;
        case RV64_SYS_setxattr: 
			assert(0 && RV64_SYS_setxattr);
			break;
        case RV64_SYS_lsetxattr: 
			assert(0 && RV64_SYS_lsetxattr);
			break;
        case RV64_SYS_fsetxattr: 
			assert(0 && RV64_SYS_fsetxattr);
			break;
        case RV64_SYS_getxattr: 
			assert(0 && RV64_SYS_getxattr);
			break;
        case RV64_SYS_lgetxattr: 
			assert(0 && RV64_SYS_lgetxattr);
			break;
        case RV64_SYS_fgetxattr: 
			assert(0 && RV64_SYS_fgetxattr);
			break;
        case RV64_SYS_listxattr: 
			assert(0 && RV64_SYS_listxattr);
			break;
        case RV64_SYS_llistxattr: 
			assert(0 && RV64_SYS_llistxattr);
			break;
        case RV64_SYS_flistxattr: 
			assert(0 && RV64_SYS_flistxattr);
			break;
        case RV64_SYS_removexattr: 
			assert(0 && RV64_SYS_removexattr);
			break;
        case RV64_SYS_lremovexattr: 
			assert(0 && RV64_SYS_lremovexattr);
			break;
        case RV64_SYS_fremovexattr: 
			assert(0 && RV64_SYS_fremovexattr);
			break;
        case RV64_SYS_getcwd: 
			assert(0 && RV64_SYS_getcwd);
			break;
        case RV64_SYS_lookup_dcookie: 
			assert(0 && RV64_SYS_lookup_dcookie);
			break;
        case RV64_SYS_eventfd2: 
			assert(0 && RV64_SYS_eventfd2);
			break;
        case RV64_SYS_epoll_create1: 
			assert(0 && RV64_SYS_epoll_create1);
			break;
        case RV64_SYS_epoll_ctl: 
			assert(0 && RV64_SYS_epoll_ctl);
			break;
        case RV64_SYS_epoll_pwait: 
			assert(0 && RV64_SYS_epoll_pwait);
			break;
        case RV64_SYS_dup: 
			assert(0 && RV64_SYS_dup);
			break;
        case RV64_SYS_dup3: 
			assert(0 && RV64_SYS_dup3);
			break;
        case RV64_SYS_fcntl: 
			assert(0 && RV64_SYS_fcntl);
			break;
        case RV64_SYS_inotify_init1: 
			assert(0 && RV64_SYS_inotify_init1);
			break;
        case RV64_SYS_inotify_add_watch: 
			assert(0 && RV64_SYS_inotify_add_watch);
			break;
        case RV64_SYS_inotify_rm_watch: 
			assert(0 && RV64_SYS_inotify_rm_watch);
			break;
        case RV64_SYS_ioctl: 
			assert(0 && RV64_SYS_ioctl);
			break;
        case RV64_SYS_ioprio_set: 
			assert(0 && RV64_SYS_ioprio_set);
			break;
        case RV64_SYS_ioprio_get: 
			assert(0 && RV64_SYS_ioprio_get);
			break;
        case RV64_SYS_flock: 
			assert(0 && RV64_SYS_flock);
			break;
        case RV64_SYS_mknodat: 
			assert(0 && RV64_SYS_mknodat);
			break;
        case RV64_SYS_mkdirat: 
			assert(0 && RV64_SYS_mkdirat);
			break;
        case RV64_SYS_unlinkat: 
			assert(0 && RV64_SYS_unlinkat);
			break;
        case RV64_SYS_symlinkat: 
			assert(0 && RV64_SYS_symlinkat);
			break;
        case RV64_SYS_linkat: 
			assert(0 && RV64_SYS_linkat);
			break;
        case RV64_SYS_renameat: 
			assert(0 && RV64_SYS_renameat);
			break;
        case RV64_SYS_umount2: 
			assert(0 && RV64_SYS_umount2);
			break;
        case RV64_SYS_mount: 
			assert(0 && RV64_SYS_mount);
			break;
        case RV64_SYS_pivot_root: 
			assert(0 && RV64_SYS_pivot_root);
			break;
        case RV64_SYS_nfsservctl: 
			assert(0 && RV64_SYS_nfsservctl);
			break;
        case RV64_SYS_statfs: 
			assert(0 && RV64_SYS_statfs);
			break;
        case RV64_SYS_fstatfs: 
			assert(0 && RV64_SYS_fstatfs);
			break;
        case RV64_SYS_truncate: 
			assert(0 && RV64_SYS_truncate);
			break;
        case RV64_SYS_ftruncate: 
			assert(0 && RV64_SYS_ftruncate);
			break;
        case RV64_SYS_fallocate: 
			assert(0 && RV64_SYS_fallocate);
			break;
        case RV64_SYS_faccessat: 
			assert(0 && RV64_SYS_faccessat);
			break;
        case RV64_SYS_chdir: 
			assert(0 && RV64_SYS_chdir);
			break;
        case RV64_SYS_fchdir: 
			assert(0 && RV64_SYS_fchdir);
			break;
        case RV64_SYS_chroot: 
			assert(0 && RV64_SYS_chroot);
			break;
        case RV64_SYS_fchmod: 
			assert(0 && RV64_SYS_fchmod);
			break;
        case RV64_SYS_fchmodat: 
			assert(0 && RV64_SYS_fchmodat);
			break;
        case RV64_SYS_fchownat: 
			assert(0 && RV64_SYS_fchownat);
			break;
        case RV64_SYS_fchown: 
			assert(0 && RV64_SYS_fchown);
			break;
        case RV64_SYS_openat: 
			assert(0 && RV64_SYS_openat);
			break;
        case RV64_SYS_close: 
			assert(0 && RV64_SYS_close);
			break;
        case RV64_SYS_vhangup: 
			assert(0 && RV64_SYS_vhangup);
			break;
        case RV64_SYS_pipe2: 
			assert(0 && RV64_SYS_pipe2);
			break;
        case RV64_SYS_quotactl: 
			assert(0 && RV64_SYS_quotactl);
			break;
        case RV64_SYS_getdents64: 
			assert(0 && RV64_SYS_getdents64);
			break;
        case RV64_SYS_lseek: 
			assert(0 && RV64_SYS_lseek);
			break;
        case RV64_SYS_read: 
			assert(0 && RV64_SYS_read);
			break;
        case RV64_SYS_write: 
			assert(0 && RV64_SYS_write);
			break;
        case RV64_SYS_readv: 
			assert(0 && RV64_SYS_readv);
			break;
        case RV64_SYS_writev: 
			assert(0 && RV64_SYS_writev);
			break;
        case RV64_SYS_pread64: 
			assert(0 && RV64_SYS_pread64);
			break;
        case RV64_SYS_pwrite64: 
			assert(0 && RV64_SYS_pwrite64);
			break;
        case RV64_SYS_preadv: 
			assert(0 && RV64_SYS_preadv);
			break;
        case RV64_SYS_pwritev: 
			assert(0 && RV64_SYS_pwritev);
			break;
        case RV64_SYS_sendfile: 
			assert(0 && RV64_SYS_sendfile);
			break;
        case RV64_SYS_pselect6: 
			assert(0 && RV64_SYS_pselect6);
			break;
        case RV64_SYS_ppoll: 
			assert(0 && RV64_SYS_ppoll);
			break;
        case RV64_SYS_signalfd4: 
			assert(0 && RV64_SYS_signalfd4);
			break;
        case RV64_SYS_vmsplice: 
			assert(0 && RV64_SYS_vmsplice);
			break;
        case RV64_SYS_splice: 
			assert(0 && RV64_SYS_splice);
			break;
        case RV64_SYS_tee: 
			assert(0 && RV64_SYS_tee);
			break;
        case RV64_SYS_readlinkat: 
			assert(0 && RV64_SYS_readlinkat);
			break;
        case RV64_SYS_fstatat: 
			assert(0 && RV64_SYS_fstatat);
			break;
        case RV64_SYS_fstat: 
			assert(0 && RV64_SYS_fstat);
			break;
        case RV64_SYS_sync: 
			assert(0 && RV64_SYS_sync);
			break;
        case RV64_SYS_fsync: 
			assert(0 && RV64_SYS_fsync);
			break;
        case RV64_SYS_fdatasync: 
			assert(0 && RV64_SYS_fdatasync);
			break;
        // case RV64_SYS_sync_file_range2:
        //  assert(0 && RV64_SYS_sync_file_range2);
		// 	break;
        case RV64_SYS_sync_file_range: 
			assert(0 && RV64_SYS_sync_file_range);
			break;
        case RV64_SYS_timerfd_create: 
			assert(0 && RV64_SYS_timerfd_create);
			break;
        case RV64_SYS_timerfd_settime: 
			assert(0 && RV64_SYS_timerfd_settime);
			break;
        case RV64_SYS_timerfd_gettime: 
			assert(0 && RV64_SYS_timerfd_gettime);
			break;
        case RV64_SYS_utimensat: 
			assert(0 && RV64_SYS_utimensat);
			break;
        case RV64_SYS_acct: 
			assert(0 && RV64_SYS_acct);
			break;
        case RV64_SYS_capget: 
			assert(0 && RV64_SYS_capget);
			break;
        case RV64_SYS_capset: 
			assert(0 && RV64_SYS_capset);
			break;
        case RV64_SYS_personality: 
			assert(0 && RV64_SYS_personality);
			break;
        case RV64_SYS_exit: 
			assert(0 && RV64_SYS_exit);
			break;
        case RV64_SYS_exit_group: 
			assert(0 && RV64_SYS_exit_group);
			break;
        case RV64_SYS_waitid: 
			assert(0 && RV64_SYS_waitid);
			break;
        case RV64_SYS_set_tid_address: 
			assert(0 && RV64_SYS_set_tid_address);
			break;
        case RV64_SYS_unshare: 
			assert(0 && RV64_SYS_unshare);
			break;
        case RV64_SYS_futex: 
			assert(0 && RV64_SYS_futex);
			break;
        case RV64_SYS_set_robust_list: 
			assert(0 && RV64_SYS_set_robust_list);
			break;
        case RV64_SYS_get_robust_list: 
			assert(0 && RV64_SYS_get_robust_list);
			break;
        case RV64_SYS_nanosleep: 
			assert(0 && RV64_SYS_nanosleep);
			break;
        case RV64_SYS_getitimer: 
			assert(0 && RV64_SYS_getitimer);
			break;
        case RV64_SYS_setitimer: 
			assert(0 && RV64_SYS_setitimer);
			break;
        case RV64_SYS_kexec_load: 
			assert(0 && RV64_SYS_kexec_load);
			break;
        case RV64_SYS_init_module: 
			assert(0 && RV64_SYS_init_module);
			break;
        case RV64_SYS_delete_module: 
			assert(0 && RV64_SYS_delete_module);
			break;
        case RV64_SYS_timer_create: 
			assert(0 && RV64_SYS_timer_create);
			break;
        case RV64_SYS_timer_gettime: 
			assert(0 && RV64_SYS_timer_gettime);
			break;
        case RV64_SYS_timer_getoverrun: 
			assert(0 && RV64_SYS_timer_getoverrun);
			break;
        case RV64_SYS_timer_settime: 
			assert(0 && RV64_SYS_timer_settime);
			break;
        case RV64_SYS_timer_delete: 
			assert(0 && RV64_SYS_timer_delete);
			break;
        case RV64_SYS_clock_settime: 
			assert(0 && RV64_SYS_clock_settime);
			break;
        case RV64_SYS_clock_gettime: 
			assert(0 && RV64_SYS_clock_gettime);
			break;
        case RV64_SYS_clock_getres: 
			assert(0 && RV64_SYS_clock_getres);
			break;
        case RV64_SYS_clock_nanosleep: 
			assert(0 && RV64_SYS_clock_nanosleep);
			break;
        case RV64_SYS_syslog: 
			assert(0 && RV64_SYS_syslog);
			break;
        case RV64_SYS_ptrace: 
			assert(0 && RV64_SYS_ptrace);
			break;
        case RV64_SYS_sched_setparam: 
			assert(0 && RV64_SYS_sched_setparam);
			break;
        case RV64_SYS_sched_setscheduler: 
			assert(0 && RV64_SYS_sched_setscheduler);
			break;
        case RV64_SYS_sched_getscheduler: 
			assert(0 && RV64_SYS_sched_getscheduler);
			break;
        case RV64_SYS_sched_getparam: 
			assert(0 && RV64_SYS_sched_getparam);
			break;
        case RV64_SYS_sched_setaffinity: 
			assert(0 && RV64_SYS_sched_setaffinity);
			break;
        case RV64_SYS_sched_getaffinity: 
			assert(0 && RV64_SYS_sched_getaffinity);
			break;
        case RV64_SYS_sched_yield: 
			assert(0 && RV64_SYS_sched_yield);
			break;
        case RV64_SYS_sched_get_priority_max: 
			assert(0 && RV64_SYS_sched_get_priority_max);
			break;
        case RV64_SYS_sched_get_priority_min: 
			assert(0 && RV64_SYS_sched_get_priority_min);
			break;
        case RV64_SYS_sched_rr_get_interval: 
			assert(0 && RV64_SYS_sched_rr_get_interval);
			break;
        case RV64_SYS_restart_syscall: 
			assert(0 && RV64_SYS_restart_syscall);
			break;
        case RV64_SYS_kill: 
			assert(0 && RV64_SYS_kill);
			break;
        case RV64_SYS_tkill: 
			assert(0 && RV64_SYS_tkill);
			break;
        case RV64_SYS_tgkill: 
			assert(0 && RV64_SYS_tgkill);
			break;
        case RV64_SYS_sigaltstack: 
			assert(0 && RV64_SYS_sigaltstack);
			break;
        case RV64_SYS_rt_sigsuspend: 
			assert(0 && RV64_SYS_rt_sigsuspend);
			break;
        case RV64_SYS_rt_sigaction: 
			assert(0 && RV64_SYS_rt_sigaction);
			break;
        case RV64_SYS_rt_sigprocmask: 
			assert(0 && RV64_SYS_rt_sigprocmask);
			break;
        case RV64_SYS_rt_sigpending: 
			assert(0 && RV64_SYS_rt_sigpending);
			break;
        case RV64_SYS_rt_sigtimedwait: 
			assert(0 && RV64_SYS_rt_sigtimedwait);
			break;
        case RV64_SYS_rt_sigqueueinfo: 
			assert(0 && RV64_SYS_rt_sigqueueinfo);
			break;
        case RV64_SYS_rt_sigreturn: 
			assert(0 && RV64_SYS_rt_sigreturn);
			break;
        case RV64_SYS_setpriority: 
			assert(0 && RV64_SYS_setpriority);
			break;
        case RV64_SYS_getpriority: 
			assert(0 && RV64_SYS_getpriority);
			break;
        case RV64_SYS_reboot: 
			assert(0 && RV64_SYS_reboot);
			break;
        case RV64_SYS_setregid: 
			assert(0 && RV64_SYS_setregid);
			break;
        case RV64_SYS_setgid: 
			assert(0 && RV64_SYS_setgid);
			break;
        case RV64_SYS_setreuid: 
			assert(0 && RV64_SYS_setreuid);
			break;
        case RV64_SYS_setuid: 
			assert(0 && RV64_SYS_setuid);
			break;
        case RV64_SYS_setresuid: 
			assert(0 && RV64_SYS_setresuid);
			break;
        case RV64_SYS_getresuid: 
			assert(0 && RV64_SYS_getresuid);
			break;
        case RV64_SYS_setresgid: 
			assert(0 && RV64_SYS_setresgid);
			break;
        case RV64_SYS_getresgid: 
			assert(0 && RV64_SYS_getresgid);
			break;
        case RV64_SYS_setfsuid: 
			assert(0 && RV64_SYS_setfsuid);
			break;
        case RV64_SYS_setfsgid: 
			assert(0 && RV64_SYS_setfsgid);
			break;
        case RV64_SYS_times: 
			assert(0 && RV64_SYS_times);
			break;
        case RV64_SYS_setpgid: 
			assert(0 && RV64_SYS_setpgid);
			break;
        case RV64_SYS_getpgid: 
			assert(0 && RV64_SYS_getpgid);
			break;
        case RV64_SYS_getsid: 
			assert(0 && RV64_SYS_getsid);
			break;
        case RV64_SYS_setsid: 
			assert(0 && RV64_SYS_setsid);
			break;
        case RV64_SYS_getgroups: 
			assert(0 && RV64_SYS_getgroups);
			break;
        case RV64_SYS_setgroups: 
			assert(0 && RV64_SYS_setgroups);
			break;
        case RV64_SYS_uname: 
			assert(0 && RV64_SYS_uname);
			break;
        case RV64_SYS_sethostname: 
			assert(0 && RV64_SYS_sethostname);
			break;
        case RV64_SYS_setdomainname: 
			assert(0 && RV64_SYS_setdomainname);
			break;
        case RV64_SYS_getrlimit: 
			assert(0 && RV64_SYS_getrlimit);
			break;
        case RV64_SYS_setrlimit: 
			assert(0 && RV64_SYS_setrlimit);
			break;
        case RV64_SYS_getrusage: 
			assert(0 && RV64_SYS_getrusage);
			break;
        case RV64_SYS_umask: 
			assert(0 && RV64_SYS_umask);
			break;
        case RV64_SYS_prctl: 
			assert(0 && RV64_SYS_prctl);
			break;
        case RV64_SYS_getcpu: 
			assert(0 && RV64_SYS_getcpu);
			break;
        case RV64_SYS_gettimeofday: 
			assert(0 && RV64_SYS_gettimeofday);
			break;
        case RV64_SYS_settimeofday: 
			assert(0 && RV64_SYS_settimeofday);
			break;
        case RV64_SYS_adjtimex: 
			assert(0 && RV64_SYS_adjtimex);
			break;
        case RV64_SYS_getpid: 
			assert(0 && RV64_SYS_getpid);
			break;
        case RV64_SYS_getppid: 
			assert(0 && RV64_SYS_getppid);
			break;
        case RV64_SYS_getuid: 
			assert(0 && RV64_SYS_getuid);
			break;
        case RV64_SYS_geteuid: 
			assert(0 && RV64_SYS_geteuid);
			break;
        case RV64_SYS_getgid: 
			assert(0 && RV64_SYS_getgid);
			break;
        case RV64_SYS_getegid: 
			assert(0 && RV64_SYS_getegid);
			break;
        case RV64_SYS_gettid: 
			assert(0 && RV64_SYS_gettid);
			break;
        case RV64_SYS_sysinfo: 
			assert(0 && RV64_SYS_sysinfo);
			break;
        case RV64_SYS_mq_open: 
			assert(0 && RV64_SYS_mq_open);
			break;
        case RV64_SYS_mq_unlink: 
			assert(0 && RV64_SYS_mq_unlink);
			break;
        case RV64_SYS_mq_timedsend: 
			assert(0 && RV64_SYS_mq_timedsend);
			break;
        case RV64_SYS_mq_timedreceive: 
			assert(0 && RV64_SYS_mq_timedreceive);
			break;
        case RV64_SYS_mq_notify: 
			assert(0 && RV64_SYS_mq_notify);
			break;
        case RV64_SYS_mq_getsetattr: 
			assert(0 && RV64_SYS_mq_getsetattr);
			break;
        case RV64_SYS_msgget: 
			assert(0 && RV64_SYS_msgget);
			break;
        case RV64_SYS_msgctl: 
			assert(0 && RV64_SYS_msgctl);
			break;
        case RV64_SYS_msgrcv: 
			assert(0 && RV64_SYS_msgrcv);
			break;
        case RV64_SYS_msgsnd: 
			assert(0 && RV64_SYS_msgsnd);
			break;
        case RV64_SYS_semget: 
			assert(0 && RV64_SYS_semget);
			break;
        case RV64_SYS_semctl: 
			assert(0 && RV64_SYS_semctl);
			break;
        case RV64_SYS_semtimedop: 
			assert(0 && RV64_SYS_semtimedop);
			break;
        case RV64_SYS_semop: 
			assert(0 && RV64_SYS_semop);
			break;
        case RV64_SYS_shmget: 
			assert(0 && RV64_SYS_shmget);
			break;
        case RV64_SYS_shmctl: 
			assert(0 && RV64_SYS_shmctl);
			break;
        case RV64_SYS_shmat: 
			assert(0 && RV64_SYS_shmat);
			break;
        case RV64_SYS_shmdt: 
			assert(0 && RV64_SYS_shmdt);
			break;
        case RV64_SYS_socket: 
			assert(0 && RV64_SYS_socket);
			break;
        case RV64_SYS_socketpair: 
			assert(0 && RV64_SYS_socketpair);
			break;
        case RV64_SYS_bind: 
			assert(0 && RV64_SYS_bind);
			break;
        case RV64_SYS_listen: 
			assert(0 && RV64_SYS_listen);
			break;
        case RV64_SYS_accept: 
			assert(0 && RV64_SYS_accept);
			break;
        case RV64_SYS_connect: 
			assert(0 && RV64_SYS_connect);
			break;
        case RV64_SYS_getsockname: 
			assert(0 && RV64_SYS_getsockname);
			break;
        case RV64_SYS_getpeername: 
			assert(0 && RV64_SYS_getpeername);
			break;
        case RV64_SYS_sendto: 
			assert(0 && RV64_SYS_sendto);
			break;
        case RV64_SYS_recvfrom: 
			assert(0 && RV64_SYS_recvfrom);
			break;
        case RV64_SYS_setsockopt: 
			assert(0 && RV64_SYS_setsockopt);
			break;
        case RV64_SYS_getsockopt: 
			assert(0 && RV64_SYS_getsockopt);
			break;
        case RV64_SYS_shutdown: 
			assert(0 && RV64_SYS_shutdown);
			break;
        case RV64_SYS_sendmsg: 
			assert(0 && RV64_SYS_sendmsg);
			break;
        case RV64_SYS_recvmsg: 
			assert(0 && RV64_SYS_recvmsg);
			break;
        case RV64_SYS_readahead: 
			assert(0 && RV64_SYS_readahead);
			break;
        case RV64_SYS_brk:
            assert(0 && RV64_SYS_brk);
			break;
        case RV64_SYS_munmap: 
			assert(0 && RV64_SYS_munmap);
			break;
        case RV64_SYS_mremap: 
			assert(0 && RV64_SYS_mremap);
			break;
        case RV64_SYS_add_key: 
			assert(0 && RV64_SYS_add_key);
			break;
        case RV64_SYS_request_key: 
			assert(0 && RV64_SYS_request_key);
			break;
        case RV64_SYS_keyctl: 
			assert(0 && RV64_SYS_keyctl);
			break;
        case RV64_SYS_clone: 
			assert(0 && RV64_SYS_clone);
			break;
        case RV64_SYS_execve: 
			assert(0 && RV64_SYS_execve);
			break;
        case RV64_SYS_mmap: 
			assert(0 && RV64_SYS_mmap);
			break;
        case RV64_SYS_fadvise64: 
			assert(0 && RV64_SYS_fadvise64);
			break;
        case RV64_SYS_swapon: 
			assert(0 && RV64_SYS_swapon);
			break;
        case RV64_SYS_swapoff: 
			assert(0 && RV64_SYS_swapoff);
			break;
        case RV64_SYS_mprotect: 
			assert(0 && RV64_SYS_mprotect);
			break;
        case RV64_SYS_msync: 
			assert(0 && RV64_SYS_msync);
			break;
        case RV64_SYS_mlock: 
			assert(0 && RV64_SYS_mlock);
			break;
        case RV64_SYS_munlock: 
			assert(0 && RV64_SYS_munlock);
			break;
        case RV64_SYS_mlockall: 
			assert(0 && RV64_SYS_mlockall);
			break;
        case RV64_SYS_munlockall: 
			assert(0 && RV64_SYS_munlockall);
			break;
        case RV64_SYS_mincore: 
			assert(0 && RV64_SYS_mincore);
			break;
        case RV64_SYS_madvise: 
			assert(0 && RV64_SYS_madvise);
			break;
        case RV64_SYS_remap_file_pages: 
			assert(0 && RV64_SYS_remap_file_pages);
			break;
        case RV64_SYS_mbind: 
			assert(0 && RV64_SYS_mbind);
			break;
        case RV64_SYS_get_mempolicy: 
			assert(0 && RV64_SYS_get_mempolicy);
			break;
        case RV64_SYS_set_mempolicy: 
			assert(0 && RV64_SYS_set_mempolicy);
			break;
        case RV64_SYS_migrate_pages: 
			assert(0 && RV64_SYS_migrate_pages);
			break;
        case RV64_SYS_move_pages: 
			assert(0 && RV64_SYS_move_pages);
			break;
        case RV64_SYS_rt_tgsigqueueinfo: 
			assert(0 && RV64_SYS_rt_tgsigqueueinfo);
			break;
        case RV64_SYS_perf_event_open: 
			assert(0 && RV64_SYS_perf_event_open);
			break;
        case RV64_SYS_accept4: 
			assert(0 && RV64_SYS_accept4);
			break;
        case RV64_SYS_recvmmsg: 
			assert(0 && RV64_SYS_recvmmsg);
			break;
        case RV64_SYS_arch_specific_syscall: 
			assert(0 && RV64_SYS_arch_specific_syscall);
			break;
        case RV64_SYS_wait4: 
			assert(0 && RV64_SYS_wait4);
			break;
        case RV64_SYS_prlimit64: 
			assert(0 && RV64_SYS_prlimit64);
			break;
        case RV64_SYS_fanotify_init: 
			assert(0 && RV64_SYS_fanotify_init);
			break;
        case RV64_SYS_fanotify_mark: 
			assert(0 && RV64_SYS_fanotify_mark);
			break;
        case RV64_SYS_name_to_handle_at: 
			assert(0 && RV64_SYS_name_to_handle_at);
			break;
        case RV64_SYS_open_by_handle_at:
            break;
        case RV64_SYS_clock_adjtime: 
			assert(0 && RV64_SYS_clock_adjtime);
			break;
        case RV64_SYS_syncfs: 
			assert(0 && RV64_SYS_syncfs);
			break;
        case RV64_SYS_setns: 
			assert(0 && RV64_SYS_setns);
			break;
        case RV64_SYS_sendmmsg: 
			assert(0 && RV64_SYS_sendmmsg);
			break;
        case RV64_SYS_process_vm_readv: 
			assert(0 && RV64_SYS_process_vm_readv);
			break;
        case RV64_SYS_process_vm_writev: 
			assert(0 && RV64_SYS_process_vm_writev);
			break;
        case RV64_SYS_kcmp: 
			assert(0 && RV64_SYS_kcmp);
			break;
        case RV64_SYS_finit_module: 
			assert(0 && RV64_SYS_finit_module);
			break;
        case RV64_SYS_sched_setattr: 
			assert(0 && RV64_SYS_sched_setattr);
			break;
        case RV64_SYS_sched_getattr: 
			assert(0 && RV64_SYS_sched_getattr);
			break;
        case RV64_SYS_renameat2: 
			assert(0 && RV64_SYS_renameat2);
			break;
        case RV64_SYS_seccomp: 
			assert(0 && RV64_SYS_seccomp);
			break;
        case RV64_SYS_getrandom: 
			assert(0 && RV64_SYS_getrandom);
			break;
        case RV64_SYS_memfd_create: 
			assert(0 && RV64_SYS_memfd_create);
			break;
        case RV64_SYS_bpf: 
			assert(0 && RV64_SYS_bpf);
			break;
        case RV64_SYS_execveat: 
			assert(0 && RV64_SYS_execveat);
			break;
        case RV64_SYS_userfaultfd: 
			assert(0 && RV64_SYS_userfaultfd);
			break;
        case RV64_SYS_membarrier: 
			assert(0 && RV64_SYS_membarrier);
			break;
        case RV64_SYS_mlock2: 
			assert(0 && RV64_SYS_mlock2);
			break;
        case RV64_SYS_copy_file_range: 
			assert(0 && RV64_SYS_copy_file_range);
			break;
        case RV64_SYS_preadv2: 
			assert(0 && RV64_SYS_preadv2);
			break;
        case RV64_SYS_pwritev2: 
			assert(0 && RV64_SYS_pwritev2);
			break;
        case RV64_SYS_pkey_mprotect: 
			assert(0 && RV64_SYS_pkey_mprotect);
			break;
        case RV64_SYS_pkey_alloc: 
			assert(0 && RV64_SYS_pkey_alloc);
			break;
        case RV64_SYS_pkey_free: 
			assert(0 && RV64_SYS_pkey_free);
			break;
        case RV64_SYS_statx: 
			assert(0 && RV64_SYS_statx);
			break;
        case RV64_SYS_io_pgetevents: 
			assert(0 && RV64_SYS_io_pgetevents);
			break;
        case RV64_SYS_rseq: 
			assert(0 && RV64_SYS_rseq);
			break;
        case RV64_SYS_kexec_file_load: 
			assert(0 && RV64_SYS_kexec_file_load);
			break;
        case RV64_SYS_clock_gettime64: 
			assert(0 && RV64_SYS_clock_gettime64);
			break;
        case RV64_SYS_clock_settime64: 
			assert(0 && RV64_SYS_clock_settime64);
			break;
        case RV64_SYS_clock_adjtime64: 
			assert(0 && RV64_SYS_clock_adjtime64);
			break;
        case RV64_SYS_clock_getres_time64: 
			assert(0 && RV64_SYS_clock_getres_time64);
			break;
        case RV64_SYS_clock_nanosleep_time64: 
			assert(0 && RV64_SYS_clock_nanosleep_time64);
			break;
        case RV64_SYS_timer_gettime64: 
			assert(0 && RV64_SYS_timer_gettime64);
			break;
        case RV64_SYS_timer_settime64: 
			assert(0 && RV64_SYS_timer_settime64);
			break;
        case RV64_SYS_timerfd_gettime64: 
			assert(0 && RV64_SYS_timerfd_gettime64);
			break;
        case RV64_SYS_timerfd_settime64: 
			assert(0 && RV64_SYS_timerfd_settime64);
			break;
        case RV64_SYS_utimensat_time64: 
			assert(0 && RV64_SYS_utimensat_time64);
			break;
        case RV64_SYS_pselect6_time64: 
			assert(0 && RV64_SYS_pselect6_time64);
			break;
        case RV64_SYS_ppoll_time64: 
			assert(0 && RV64_SYS_ppoll_time64);
			break;
        case RV64_SYS_io_pgetevents_time64: 
			assert(0 && RV64_SYS_io_pgetevents_time64);
			break;
        case RV64_SYS_recvmmsg_time64: 
			assert(0 && RV64_SYS_recvmmsg_time64);
			break;
        case RV64_SYS_mq_timedsend_time64: 
			assert(0 && RV64_SYS_mq_timedsend_time64);
			break;
        case RV64_SYS_mq_timedreceive_time64: 
			assert(0 && RV64_SYS_mq_timedreceive_time64);
			break;
        case RV64_SYS_semtimedop_time64: 
			assert(0 && RV64_SYS_semtimedop_time64);
			break;
        case RV64_SYS_rt_sigtimedwait_time64: 
			assert(0 && RV64_SYS_rt_sigtimedwait_time64);
			break;
        case RV64_SYS_futex_time64: 
			assert(0 && RV64_SYS_futex_time64);
			break;
        case RV64_SYS_sched_rr_get_interval_time64: 
			assert(0 && RV64_SYS_sched_rr_get_interval_time64);
			break;
        case RV64_SYS_pidfd_send_signal: 
			assert(0 && RV64_SYS_pidfd_send_signal);
			break;
        case RV64_SYS_io_uring_setup: 
			assert(0 && RV64_SYS_io_uring_setup);
			break;
        case RV64_SYS_io_uring_enter: 
			assert(0 && RV64_SYS_io_uring_enter);
			break;
        case RV64_SYS_io_uring_register: 
			assert(0 && RV64_SYS_io_uring_register);
			break;
        case RV64_SYS_open_tree: 
			assert(0 && RV64_SYS_open_tree);
			break;
        case RV64_SYS_move_mount: 
			assert(0 && RV64_SYS_move_mount);
			break;
        case RV64_SYS_fsopen: 
			assert(0 && RV64_SYS_fsopen);
			break;
        case RV64_SYS_fsconfig: 
			assert(0 && RV64_SYS_fsconfig);
			break;
        case RV64_SYS_fsmount: 
			assert(0 && RV64_SYS_fsmount);
			break;
        case RV64_SYS_fspick: 
			assert(0 && RV64_SYS_fspick);
			break;
        case RV64_SYS_pidfd_open: 
			assert(0 && RV64_SYS_pidfd_open);
			break;
        case RV64_SYS_clone3: 
			assert(0 && RV64_SYS_clone3);
			break;
        case RV64_SYS_close_range: 
			assert(0 && RV64_SYS_close_range);
			break;
        case RV64_SYS_openat2: 
			assert(0 && RV64_SYS_openat2);
			break;
        case RV64_SYS_pidfd_getfd: 
			assert(0 && RV64_SYS_pidfd_getfd);
			break;
        case RV64_SYS_faccessat2: 
			assert(0 && RV64_SYS_faccessat2);
			break;
        case RV64_SYS_process_madvise: 
			assert(0 && RV64_SYS_process_madvise);
			break;
        case RV64_SYS_epoll_pwait2: 
			assert(0 && RV64_SYS_epoll_pwait2);
			break;
        case RV64_SYS_mount_setattr: 
			assert(0 && RV64_SYS_mount_setattr);
			break;
        case RV64_SYS_quotactl_fd: 
			assert(0 && RV64_SYS_quotactl_fd);
			break;
        case RV64_SYS_landlock_create_ruleset: 
			assert(0 && RV64_SYS_landlock_create_ruleset);
			break;
        case RV64_SYS_landlock_add_rule: 
			assert(0 && RV64_SYS_landlock_add_rule);
			break;
        case RV64_SYS_landlock_restrict_self: 
			assert(0 && RV64_SYS_landlock_restrict_self);
			break;
        case RV64_SYS_memfd_secret: 
			assert(0 && RV64_SYS_memfd_secret);
			break;
        case RV64_SYS_process_mrelease: 
			assert(0 && RV64_SYS_process_mrelease);
			break;
        case RV64_SYS_futex_waitv: 
			assert(0 && RV64_SYS_futex_waitv);
			break;
        case RV64_SYS_set_mempolicy_home_node: 
			assert(0 && RV64_SYS_set_mempolicy_home_node);
			break;
        case RV64_SYS_cachestat: 
			assert(0 && RV64_SYS_cachestat);
			break;
        case RV64_SYS_fchmodat2: 
			assert(0 && RV64_SYS_fchmodat2);
			break;
        case RV64_SYS_syscalls: 
			assert(0 && RV64_SYS_syscalls);
			break;
        case RV64_SYS_riscv_flush_icache: 
            break;
        case RV64_SYS_riscv_hwprobe:
            break;
        default:
            printf("Syscall code not recognized: %ld", syscode);

    }
}