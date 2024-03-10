{
    "author": {
        "name": "作者：谭嘉淳",
        "url": "http://luoyebai.cn:7890"
    },
    "departments": [
    ]
}
+++++
# [🏠](../../../dist/index.html#/1)[计算机工程](https://zh.wikipedia.org/wiki/%E8%A8%88%E7%AE%97%E6%A9%9F%E5%B7%A5%E7%A8%8B)的构建与维护

> 计算机工程需要可维护性

----

## 概述

1. 从简单又常用的工具开始学习
2. CPP工具的学习
3. 编程范式与设计模式

---

# 1.简单的工具

> Simplicity is prerequisite for weliability --- Edsger Dijkstra

----

## 工程中的各种"简单"工具

- 构建工具:通过指定参数对项目进行构建生成. <br>
如:
    - [make 点击查看](https://www.gnu.org/software/make/)
    - [cmake 点击查看](https://cmake.org/)
    - [ninja 点击查看](https://ninja-build.org/)
    - [bazel 点击查看](https://bazel.build/?hl=zh-cn)
    - [xmake 点击查看](https://xmake.io/#/zh-cn/)
- 生成工具:通过项目文本或指定内容生成文件.<br>
如:
    - [doxygen 点击查看](https://www.doxygen.nl/index.html)
    - [copilot 点击查看](https://github.com/features/copilot)
    - [codegeex 点击查看](https://codegeex.cn/zh-CN)

----

- 动态分析器:对涉及执行相关程序的分析.<br>
    - 模型检验:[形式语义wiki 点击查看](https://zh.wikipedia.org/wiki/%E5%BD%A2%E5%BC%8F%E8%AF%AD%E8%A8%80)
        - [spin 点击查看](https://spinroot.com/spin/whatispin.html)
        - [model-check相关书籍 点击查看](https://is.ifmo.ru/books/_principles_of_model_checking.pdf)
    - 单元测试:
        - [google-test 点击查看](https://google.github.io/googletest/)
        - [cppunit 点击查看](https://cppunit.sourceforge.net/doc/1.8.0/)
    - 调试工具:在程序的执行过程中,暂停,插入,修改,查看其内容.<br>
        - [gdb 点击查看](https://sourceware.org/gdb/)
        - [lldb 点击查看](https://lldb.llvm.org/)
    - 性能分析:分析程序执行过程中,各部分消耗的性能相关资源.<br>
        - [perf 点击查看](https://www.brendangregg.com/perf.html)
        - [flame-graphs 点击查看](https://www.brendangregg.com/flamegraphs.html)


----

- 静态检查器:检查代码格式,内容.输出分析结果信息.<br>
    - [cppcheck 点击查看](http://cppcheck.net/)
    - [clang-tidy 点击查看](https://clang.llvm.org/extra/clang-tidy/)

- 管理工具:管理代码版本和内容,方便维护代码.<br>
如:
    - [git 点击查看](https://git-scm.com/) 
    - [svn 点击查看](https://tortoisesvn.net/)

- 打包工具:对制作好的程序进行包装部署,简化部署流程.<br>
如:
    - [docker 点击查看](https://www.docker.com/)
    - [podman 点击查看](https://podman.io/)

> 这些工具共同作用于程工程项目,提供一个良好的可维护环境

---

# 2. CPP工程中的工具学习<br><red>(TODO:待更新)</red>

> 好的工程能准确地传达工程师的思想与目的

----

## 好的工具是工程师实现与传递思想的武器

- 有什么工具就在很大程度上意味着需要做什么<br>
    -  工具是工程实现流程的体现
    - 知道需要什么工具可能比工具本身更重要

- 工具代表了开发环节
    - 每个工具侧重的方向不同
    - 理解每个工具的目的才是重点

> 编辑器在代码编写过程中最为重要,既代码才是重中之重

---

## 构建工具:[make](https://www.gnu.org/software/make/)->[cmake](https://cmake.org/)->[xmake](https://xmake.io/#/zh-cn/)

- 先讲讲构建工具<br>
Q1:构建为什么是必要的流程?<br>
Q2:如何更好地构建?<br>

- 回答这两个问题,从具体的工具出发可能会更清晰<br>
先看看使用makefile构建的这样一个工程<br>

```
./code
├── build
│   ├── main
│   └── sum.o
├── include
│   └── sum.h
├── makefile
└── src
    ├── main.c
    └── sum.c
4 directories, 6 files
```

----

### 看看makefile

- 这样一个工程很简单,使用make编译就好<br>
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
```

----

### Q1:构建为什么是必要的流程<br>

- 从makefile中我们可以得到很多信息<br>
这是在.c和.h代码中很难得到的信息,这个makefile它告诉了我们<br>

- 程序的结构
    - 源码->src
    - 头文件->include
    - 生成文件->build
- 编译的参数
    - 使用g++命令编译,而不是gcc(这意味着之后可能引入cpp文件)
    - -O2 使用等级为2的优化,而且没有-g,意味着这不是debug模式

> 构建这一步骤不仅仅是提供了方便,而且给出了很多源码没有的信息,这也许更为重要

----

### Q2:如何更好的构建<br>

- 上述的构建模式很好,这像极了从<blue>汇编到c</blue>的过程<br>
我们有一套很不错的构建模式了

- 但也正如c语言完成了历史任务一般,我们可以做的更好
- <red>如c到c++一般,makefile便要到cmake了</red>

> 从makefile到cmake,构建体系逐渐完善

#### 为什么要从makefile到cmake?

- makefile很方便了,在上面可以指定编译的工具,文件位置等参数<br>
貌似没什么缺点,写下命令就可以自动化工作.<br>

> 但是这种构造合理吗? 或者说有没有可能更好?

----

#### makefile带来的缺点

- makefile的缺点和c语言很像,没有深层次的特性和抽象<br>
即过于简单,而带来的两个问题
    - 因为简易性而带来的<red>信息不足</red><br>
     这个问题可以用注释,规范,和大量的变量去解决
    - 因为简单性而导致的<red>抽象不足</red>


- 但面对第二个问题,抽象不足带来的最大毛病则是,工程量变大时
makefile的手写会很麻烦,而且想要跨平台也很复杂<br>
    - 根据我们从工程中汲取的经验,是时候换一种方式:<br>
        写一个专门生成makefile的"语言"了<br>

----

#### makefile->cmake

- 文档相关
    - [cmake教程 点击查看](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)<br>
    - [CMakeLists.txt例子 点击查看](./code/CMakeLists.txt)

- 事实上cmake也很好地接过了makefile的"部分工作", 而且在一定程度成为了c++工程最常用的构建工具<br>
    - 它可以跨平台构建,生成makefile,所以,它成功了吗?

> **我想,并没有完全成功**

----
#### 2023年的今天

- 2023年的今天,**CMake依然只有57%的占比**
    - [c++2023生态 | jetbrains 点击查看](https://www.jetbrains.com/zh-cn/lp/devecosystem-2023/cpp/)
    - 重复历史一般地,如同c++没有取代c,cmake也没有取代make

- 但是cmake已经做的很好了,解决了makefile的许多问题.
    - 但是仍有个老生常谈的问题没能解决---"依赖管理"
    - 我们很难把所有的功能都留给自己写,很显然
    - 大量的开发者依赖于第三方库

- 所以涌现了许多"新新势力"
    - 其中最为出名的则是<blue>xmake</blue>

> 当然,构建工具的发展是必然的

----

### 本节仅为拓展:xmake的依赖管理

> "依赖管理"是个大问题

- xmake在一定程度上解决了这个问题<br>
- 并且,xmake的体感比cmake要好,这是不得不承认的
    - 首先它使用lua语言进行编写,语法相对简单
    - 其次它有自己的依赖管理:[点击查看](https://xmake.io/#/zh-cn/manual/package_dependencies)
    - 最后它甚至有**自动生成(虽然还不太好用)**:[点击查看](https://xmake.io/#/zh-cn/features/autogen)
- 虽然它解决了cmake一部分痛点
- 到底是否应该使用xmake还需要自己体验后,再决定

---

## 文档生成器:doxygen

- 代码中第一重要的是代码
- 那第二重要的是什么呢?
    - 是注释
    - 有这么一个工具,在你写了注释之后帮你生成文档
        - 不仅可以搜索API,接口
        - 而且生成依赖路径,UML图
        - 可以显示公式,列表

- 为注释提供一个生成文档的工具,好比给写代码的时候提供LSP服务一样重要<br>
- 这里提供一份[doxygen file](../code/Doxyfile)

> 写注释都多了几分动力

---
## 调试器:gdb

- 调试工具应该都用过,IDE打断点都会
- 这些IDE实际上是对gdb或其他调试工具进行了包装


---

## 静态检查器:cppcheck

---

## 动态分析器:spin,perf,boost test

---
## 项目管理:git

---

## 打包部署工具:docker

---

# 3. 编程范式与设计模式的思考<br><red>(TODO:待更新)</red>

> 没有结构组织的代码只会是混乱不堪的散沙

----

## 系统地处理可维护性

回到工程的主体,代码身上,编程范式和设计模式往往贯穿代码始终<br>

- [编程范式 点击查看](https://zh.wikipedia.org/wiki/%E7%BC%96%E7%A8%8B%E8%8C%83%E5%9E%8B)<br>
- [设计模式 点击查看](<https://zh.wikipedia.org/wiki/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F(%E8%AE%A1%E7%AE%97%E6%9C%BA)>)

编程范式侧重思考问题的角度:[点击查看](https://www.indicative.com/resource/programming-paradigm/)<br>
设计模式则侧重代码之间的设计结构:[点击查看](https://refactoringguru.cn/)

----
## 编程语言相关
- 文档
    - [编程语言理论wiki 点击查看](https://zh.wikipedia.org/wiki/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80%E7%90%86%E8%AB%96)
    - [某些plt相关文档 点击查看](https://github.com/FrankHB/pl-docs/tree/master/zh-CN)
    - [PFDS 点击查看](https://en.wikipedia.org/wiki/Purely_functional_data_structure)

