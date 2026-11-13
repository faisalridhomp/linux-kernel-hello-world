# Linux Kernel Hello World

The classic first Linux kernel module. When loaded it prints
`Hello, World!` to the kernel log; when unloaded it prints
`Goodbye, World!`.

This is the "hello world" of kernel development: one C file
(`hello.c`), one `Makefile`, nothing else. It shows the two
things every kernel module has — an **init** function that runs
on load and an **exit** function that runs on unload.

## Files

| File | What it is |
| --- | --- |
| `hello.c` | The module source. `hello_init()` runs on load, `hello_exit()` runs on unload. |
| `Makefile` | Builds `hello.ko` against the headers of your running kernel. |
| `LICENSE` | GPL-2.0, same license as the Linux kernel. |

## Requirements

- A Linux machine (or VM) with GCC and `make`
- Kernel headers matching your running kernel:

```sh
# Ubuntu / Debian
sudo apt install linux-headers-$(uname -r)

# Fedora / RHEL
sudo dnf install kernel-devel
```

## Build

```sh
make
```

This produces `hello.ko` (the loadable kernel module).

## Run it

```sh
# Load the module
sudo insmod hello.ko

# See the message in the kernel log
dmesg | tail
# ... [ 1234.567890] Hello, World! from the Linux kernel

# Unload the module
sudo rmmod hello

# See the goodbye message
dmesg | tail
# ... [ 1234.567890] Goodbye, World!
```

## How it works

- `module_init(hello_init)` — tells the kernel which function
  to call when the module is loaded.
- `module_exit(hello_exit)` — tells the kernel which function
  to call when the module is unloaded.
- `pr_info()` — prints a message to the kernel log (visible
  with `dmesg`).
- `MODULE_LICENSE("GPL")` — required. Without it the kernel
  refuses to load the module (or marks it "tainted").

## License

GPL-2.0 — same as the Linux kernel itself.
