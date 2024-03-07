#!/bin/sh

NULL="\033[0m"
GREEN="\033[32m"
LINUX=linux-6.6.1
BUSYBOX=busybox

printf "$GREEN----创建文件夹----$NULL\n"
echo bin
echo build/"$LINUX"_build
echo build/"$BUSYBOX"_build
echo build/initramfs
mkdir -p bin build/"$LINUX"_build build/"$BUSYBOX"_build build/initramfs

printf "$GREEN----$LINUX 编译----$NULL\n"
# make
cd ../build/"$LINUX"_build
cp ../../conf/.linux_config ./.config
# && make menuconfig
time make -j8 && cp ./arch/x86_64/boot/bzImage ../../bin/
cd ../../

printf "$GREEN----$BUSYBOX 编译----$NULL\n"
cd "$BUSYBOX" && make O=../build/"$BUSYBOX"_build defconfig
cd ../build/"$BUSYBOX"_build
cp ../../conf/.busybox_config ./.config
# && make menuconfig
time make -j8 && make install && cd ../../

printf "$GREEN----initramfs打包----$NULL\n"
cd build/initramfs && cp ../../conf/init ./
chmod +x init
mkdir -p bin sbin etc proc sys usr/bin usr/sbin
cp -a ../"$BUSYBOX"_build/_install/* .
find . -print0 | cpio --null -ov --format=newc |
gzip -9 >./initramfs.cpio.gz
cp ./initramfs.cpio.gz ../../bin && cd ../../
cp ./conf/run.sh ./bin
