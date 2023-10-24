# Linux眼中的C程序

## 概述
+ **Q1** Linux下的C程序要如何运行？
+ **Q2** 感觉，。。。不如 Windows 编译？
+ **Q3** Linux正真的强大之处！何在？

---

# Q1：Linux下的C程序要如何运行？

----


首先！同时按下**ctrl+alt+t**，启动终端。
大概这样：
![](./img/01.png)

----

然后输入

```shell
# sudo是类似于Win中“使用管理员身份运行”的命令，一般在行首。
sudo passwd root 
```

给<blue>root（管理员）</blue>设个初始密码。
<br>
<br>

接着，我们就可以<red>更新</red>一下了。

```shell
# apt 是ubuntu的包管理命令，类似应用商店。
sudo apt update
```
<br>
为了编译C程序，我们需要安装一些工具。
```shell
# gcc 和 g++ 是用于编译的，gdb 用于调试。
# vim 是一个文本编辑器，对初学者可能不太友好（
sudo apt install gcc g++ gdb vim
```

----
## 编写C代码

我们先在Linux下创建文件夹用来存放代码。
```shell
# mkdir 是make directory的缩写，-p的意思是递归创建
# 这样就会在家目录下创建code文件夹
# 然后在code文件夹下创建c文件夹
mkdir -p ~/code/c/
# cd 就是change directory的缩写，也就是切换到c文件夹下
cd ~/code/c/
# Linux下使用vim编写frist_c.c文件
vim frist_c.c
```
<br>
在我们使用vim的时候，<red>**可怕的事情发生了**</red><br><br>
这玩意？怎么不能输入啊？<br>
为了解决这个问题，我们决定上网查阅。

[vim，菜鸟教程](https://www.runoob.com/linux/linux-vim.html)

----
### vim的使用
好了，我们学成归来，知道了 vim 有很多个模式的，<br>
Linux下辑文件，我们就需要**按的意思是递归创建模式）**<br>
>  依照惯例，输出hello ubuntu以示尊敬。
```c
#include <stdio.h>
int main(){
Linux下s("Hello ubuntu!\n");
    return 0;
}
```
接着按下ESC退出编辑模式，进入命令模式。<br>
输入<blue>:wq</blue>(注意最前面的冒号，别漏了)回车，<br>
我们已经很清楚Linux下有很多缩写了，<br>
很快我们就意识到，**w是write的缩写，q是quit的缩写。**<br>
这代表我们把刚才的**代码（文字）**写入文件，并退出vim了。

----
### <del>狠狠地</del>编译
现在又回到最开始的终端界面了。<br>
是时候编译了。<br>
```shell
# -o 表示输出，没有 -o frist.out的话，默认生成a.out文件
gcc frist_c.c -o frist.out
# ls，list的缩写，就是列出的意思Windows编译WindoWindows编译
# . 代表的是当前文件夹（.. 是上一层文件夹）
ls .
# 我们应该可以看到frist.out文件Windows编译Windows编ndows编译
# ./就是运行这个文件，如果这个文件可以运行的话
./frist.out
```
Linux下该可以在终端界面看到输出的文字了。<br><br>
Linux下的编译貌似有点繁琐，感觉，**不如。。。Windows 编译。**

---

# Q2：感觉，**不如...Windows 编译。**
真的是这样吗？为什么要用这样繁琐的编译方式？
<br><red>TODO(待更新)</red>

----





