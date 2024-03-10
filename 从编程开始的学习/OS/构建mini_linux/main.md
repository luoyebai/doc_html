{
    "author": {
        "name": "作者：谭嘉淳",
        "url": "http://luoyebai.cn:7890"
    },
    "departments": [
        {
            "name": "CS-Self-Learning",
            "url": "https://csdiy.wiki/",
            "img_url": "./img/cs-self-learning.jpg"
        },
        {
            "name": "Github",
            "url": "https://github.com/",
            "img_url": "./img/github-log.jpg"
        },
        {
            "name":"Awesome Lists",
            "url":"https://github.com/topics/awesome",
            "img_url": "./img/awesome-logo.svg"
        }
    ]
}
+++++
# [🏠](../../../dist/index.html#/2)构建mini_linux

----

## 概述 

+ 关于[busybox](https://www.busybox.net/)/[toybox](https://landley.net/toybox/)
+ 编译[linux kernel](https://www.kernel.org/)
+ 从[qemu](https://www.qemu.org/)启动mini_linux  

---

# 关于busybox/toybox
本质上还是程序，包含了Linux命令行的实现

----

## 可能有最精简的Linux命令行工具

> 我们这次不使用包管理，而是从源码来编译

[makefile](www.gnu.org/software/make/manual/make.html)<br>

makefile 除了一些基本的语法外，<blue>本质上就是在使用shell</blue>

会命令行，在很大程序上就会makefile

makefile 可以很方便?序那让其他人使用make命令来构建项目
<del>虽然对自己不太友好</del>

先创建mini_linux文件夹。

```shell
# 当前文件夹树
> mini_linux
```

<red>拉取源码编译，要开始了。</red>

----
## 尝试拉取box源码

[busybox1.36.1压缩包](https://busybox.net/downloads/busybox-1.36.1.tar.bz2)<br>

```shell
wget https://busybox.net/downloads/busybox-1.36.1.tar.bz2
# 当前文件夹树
> mini_linux
    └── busybox-1.36.1.tar.bz2
```

# 编译Linux kernel

就像编译普通的c程序那样编译它

----

## 拉取Linux kernel源码
[linux-6.5.9](https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.5.9.tar.xz)

```shell
wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.5.9.tar.xz
# 当前文件夹树
> mini_linux
    ├── linux-6.5.9.tar.xz
    ├── busybox-1.36.1.tar.bz2
    └── busybox-1.36.1
    │   ├── ...
    │   └── build
    │       ├── ...
            ├── busybox
            └── _install
                └── _install
```

```shell
tar -vxf linux-6.5.9.tar.xz
cd linux-6.5.9 && mkdir build
make O=./build allnoconfig 
cd build && make menuconfig
# 配置
#64-bit kernel ---> yes
#General setup ---> Initial RAM filesystem and RAM disk (initramfs/initrd) support ---> yes
#General setup ---> Configure standard kernel features ---> Enable support for printk ---> yes
#Executable file formats / Emulations ---> Kernel support for ELF binaries ---> yes
#Executable file formats / Emulations ---> Kernel support for scripts starting with #! ---> yes
#Device Drivers ---> Generic Driver Options ---> Maintain a devtmpfs filesystem to mount at /dev ---> yes
#Device Drivers ---> Generic Driver Options ---> Automount devtmpfs at /dev, after the kernel mounted the rootfs ---> yes
#Device Drivers ---> Character devices ---> Enable TTY ---> yes
#Device Drivers ---> Character devices ---> Serial drivers ---> 8250/16550 and compatible serial support ---> yes
#Device Drivers ---> Character devices ---> Serial drivers ---> Console on 8250/16550 and compatible serial port ---> yes
#File systems ---> Pseudo filesystems ---> /proc file system support ---> yes
#File systems ---> Pseudo filesystems ---> sysfs file system support ---> yes
time make -j8
```

```shell
# 当前文件夹树
> mini_linux
    ├── linux-6.5.9.tar.xz
    ├── busybox-1.36.1.tar.bz2
    ├── linux-6.5.9
    │   └── build
    │       ├── ...
    │       ├── arch
    │       ├── ├── ...
    │       └── └── x86_64
    │       ├── ├── ├── ...
    │       └── └── └── boot
    │       ├── ├── ├── ├── ...
    │       └── └── └── └── bzImage
    └── busybox-1.36.1
        ├── ...
        └── build
            ├── ...
            ├── busybox
            └── _install
```

---
# 从qemu启动mini_linux
[init](../mini_linux/init)
```
mkdir initramfs 
# 把init文件放到initramfs文件夹里面
cd initramfs && chmod +x init
mkdir -p bin sbin etc proc sys usr/bin usr/sbin
cp -a ../boxbusy-1.36.1/build/_install/* .
find . -print0 | cpio --null -ov --format=newc \
  | gzip -9 > ./initramfs.cpio.gz
```
现在可以尝试运行了
[run](../mini_linux/run.sh)

```shell
cd .. && ./run.sh
```
