# [计算机工程](https://zh.wikipedia.org/wiki/%E8%A8%88%E7%AE%97%E6%A9%9F%E5%B7%A5%E7%A8%8B)的构建与维护

> 计算机工程需要可维护性


----

## 概述

1. 从简单又常用的工具开始学习
2. CPP工具的学习
3. 编程范式与设计模式

---

# 1.简单的工具

> Simplicity is prerequisite for reliability --- Edsger Dijkstra

----
## 工程中的各种"简单"工具
- 构建工具:通过指定参数对项目进行构建生成,如:[make 点击查看](https://www.gnu.org/software/make/)
- 生成工具:通过项目文本或指定内容生成文件,如:[doxygen 点击查看](https://www.doxygen.nl/index.html)
- 调试工具:在程序的执行过程中,暂停,插入,修改,查看其内容,如[gdb 点击查看](https://sourceware.org/gdb/)
- 管理工具:管理代码版本和内容,方便维护代码,如:[git 点击查看](https://git-scm.com/)
- 静态检查器:检查代码格式及内容,找出显而易见的错误和不规范编码内容,如:[cppcheck/cpplint](http://cppcheck.net/)
- 动态分析器:对涉及执行相关程序的分析,可以获得程序的大量信息,如:[spin 点击查看](https://spinroot.com/spin/whatispin.html)
- 打包工具:对制作好的程序进行包装部署,简化部署流程,如[docker 点击查看](https://www.docker.com/)

> 这些工具共同作用于程工程项目,提供一个良好的工程环境,即流程的可维护性

---
# 2. CPP工程中的工具学习<br><red>(TODO:待更新)</red>

> 好的工程能准确地传达工程师的思想与目的

----
## 好的工具是工程师实现与传递思想的武器

一个工程问题,有什么工具就在很大程度上意味着需要做什么<br>

- 工具是工程实现流程的体现
- 知道需要什么工具可能比工具本身更重要

---
## 构建工具:[make](https://www.gnu.org/software/make/),[ninja](https://ninja-build.org/),[cmake](https://cmake.org/),[xmake](https://xmake.io/#/zh-cn/)
先讲讲构建工具<br>
Q1:构建为什么是必要的流程?<br>
Q2:如何更好地构建?<br>

回答这两个问题,从具体的工具出发可能会更清晰<br>
先看看使用makefile构建的这样一个工程<br>
```
./code/
├── build
│   ├── main
│   └── sum.o
├── include
│   └── sum.h
├── makefile
└── src
    ├── main.c
    └── sum.c
4 directories, 6 files
```
----
## 看看makefile
这样一个工程很简单,使用make编译就好<br>
顺便看看[makefile文件](../code/makefile)<br>
```makefile
TARGET=main
OBJS = sum.o
CC = g++
INCLUDE_DIR=include
SRC_DIR=src
BUILD_DIR=build
CFLAGS=-I$(INCLUDE_DIR) -O2 -o

main: $(OBJS) $(SRC_DIR)/main.c
	$(CC) $(BUILD_DIR)/*.o $(SRC_DIR)/main.c $(CFLAGS) $(BUILD_DIR)/$(TARGET)

sum.o: $(SRC_DIR)/sum.c
	$(CC) -c $(SRC_DIR)/sum.c $(CFLAGS) $(BUILD_DIR)/sum.o

.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)/*
```

----
## Q1:构建为什么是必要的流程<br>

从makefile中我们可以得到很多信息<br>
这是在.c和.h代码中很难得到的信息,这个makefile它告诉了我们<br>

- 程序的结构
    + 源码->src
    + 头文件->include
    + 生成文件->build
- 编译的参数
    + 使用g++命令编译,而不是gcc(这意味着之后可能引入cpp文件)
    + -O2 使用等级为2的优化,而且没有-g,意味着这不是debug模式

> 构建这一步骤不仅仅是提供了方便,而且给出了很多源码没有的信息,这也许更为重要

----
## Q2:如何更好的构建<br>
上述的构建模式很好,这像极了从<blue>汇编到c</blue>的过程<br>
我们有一套很不错的构建模式了

- 但也正如c一般,我们可以做的更好
- <red>如c到c++一般,makefile便要到cmake了</red>

> 从makefile到cmake,构建体系逐渐完善

----
## makefile->cmake
makefile很方便了,在上面可以指定编译的工具,文件位置等参数<br>
有几个.o我就写几个.o<br>

> 但是这种构造合理吗? 或者说有没有可能更好?

- makefile貌似没什么缺点,写下命令就可以自动化工作<br>
- makefile在这点和c很像,没有特别复杂的特性,但一个东西如果过于简单,一定为存在的两个问题
    1. 因为简易性而带来的<red>信息不足</red><br>
        这个问题可以用注释,规范,和大量的变量去解决
    2. 因为简单性而导致的<red>抽象不足</red>

但面对第二个问题,抽象不足带来的最大毛病则是,工程量变大时<br>
makefile的手写会很麻烦,而且想要跨平台也很复杂<br>

----
根据我们从工程中汲取的经验,是时候换一种方式:<br>
写一个专门生成makefile的"语言"了<br>
[cmake教程 点击查看](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)<br>
[CMakeLists.txt例子 点击查看](./code/CMakeLists.txt)

事实上cmake也很好地接过了makefile的"部分工作"<br>
cmake在一定程度成为了c++工程最常用的构建工具<br>
它成功了吗?我想并没有完全成功<br>
[c++2023生态 | jetbrains 点击查看](https://www.jetbrains.com/zh-cn/lp/devecosystem-2023/cpp/)

2023年的今天,CMake依然只有57%的占比,这说明构建工具在历史发展的过程中<br>
cmake和c++一样,没能完全拿下c的"份额"<br>

cmake已经很不错了,但是c++有个老生常谈的问题"依赖管理"<br>
我们很难把所有的功能都留给自己写,很显然,开发者依赖于第三方库<br>

----
## 拓展:xmake的依赖管理

> "依赖管理"是个大问题

xmake在一定程度上解决了这个问题<br>
并且,xmake的体感比cmake要好,这是不得不承认的

- 首先它使用lua语言进行编写,语法相对简单
- 其次它有自己的依赖管理:[点击查看](https://xmake.io/#/zh-cn/manual/package_dependencies)
- 最后它甚至有**自动生成(虽然还不太好用)**:[点击查看](https://xmake.io/#/zh-cn/features/autogen)

> 这解决了cmake的一部分痛点,当然,自己体验一番是最好的

---
## 文档生成器:doxygen
代码中第一重要的是代码,第二重要的是什么呢?

- 是注释

有这么一个工具,在你写了注释之后帮你生成文档<br>

- 不仅可以搜索API,接口
- 而且生成依赖路径,UML图
- 可以显示公式,列表

为注释提供一个生成文档的工具,好比给写代码的时候提供LSP服务一样重要<br>

> 写注释都多了几分动力

---
## 调试器:gdb
---
## 项目管理:git
---
## 静态检查器:cppcheck
---
## 动态分析器:spin,perf,boost test
---
## 打包部署工具:docker

---
# 3. 编程范式与设计模式的思考<br><red>(TODO:待更新)</red>

> 没有结构组织的代码只会是混乱不堪的散沙

----
## 系统地处理可维护性
回到工程的主体,代码身上,编程范式和设计模式往往贯穿代码始终<br>

- [编程范式 点击查看](https://zh.wikipedia.org/wiki/%E7%BC%96%E7%A8%8B%E8%8C%83%E5%9E%8B)<br>
- [设计模式 点击查看](https://zh.wikipedia.org/wiki/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F(%E8%AE%A1%E7%AE%97%E6%9C%BA))

编程范式侧重思考问题的角度:[点击查看](https://www.indicative.com/resource/programming-paradigm/)<br>
设计模式则侧重代码之间的设计结构:[点击查看](https://refactoringguru.cn/)

