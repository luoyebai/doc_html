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
## 工程的各种工具
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
## 构建工具:make,ninja,cmake,xmake
----
## 文档生成器:doxygen
----
## 调试器:gdb
----
## 项目管理:git
----
## 静态检查器:cppcheck
----
## 动态分析器:spin,perf,boost test
----
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

