> &#9888;代码还在写，写了6天才写完交互框架，现在还没写到词法分析器，好伤心555\~
> 
> The code is still being written.
>
> It took 6 days just to finish the interaction framework,
>
> and I haven't even started the lexical analyzer yet.
>
> So sad 555\~

# Luyre

**Luyre（玥语言）**，编译型编程语言，一个“面向语法”编程的尝试。

**Luyre**: A compiled programming language, which is an attempt at syntax-oriented programming.

> 以下是Luyre相关信息。Here's some information about Luyre.

## Luyre 编译程序Luyre Compiler
Luyre 编译程序是一个软件程序，可以将Luyre语言代码编译为可执行文件。

The Luyre compiler is a software program that can compile Luyre language code into an executable file. 

一般地，需要一个配置文件作为命令行参数。

Usually, it needs a configuration file as a command-line argument.

### Windows系统Windows system

如果配置文件名称为`config.luyreby`，那么在命令行中，使用以下命令使用。

If the configuration file is named `config.luyreby`, then use the following command in the command line.

```
C:\Users> luyre.exe config.luyreby
```

#### 无命令行参数No command line arguments

如果不输入参数，则会得到：

If you don't enter any parameters, you'll get:

```
C:\Users> luyre.exe
 _
| |     _   _   _   _   _ __   ___
| |    | | | | | | | | | '__| / _ \
| |___ | |_| | | |_| | | |   |  __/
|_____| \__,_|  \__, | |_|    \___|
                |___/
Luyre   : A compiled programming language.
Version : a.b.c [Build: Mon dd yyyy hh:mm:ss]
----------------------------------------------------
If the configuration file is named config.luyreby,
then use the following command in the command line:
ˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋ
        C:\Users> luyre.exe config.luyreby

ˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋˋ

```

## 配置文件Configuration file

配置文件使用后缀`.luyreby`，最简单的配置文件如下所示：

Configuration files use the `.luyreby` extension. The simplest configuration file looks like this:

```
Luyre 0.5.0
LogBook logbook.lang
File 0.out 1.luyre 2.luyre
```

### 文件组File group

在配置文件中，文件组行是形如以下形式的一行，当唯一的输出文件为`0.out`，多个输入文件为`1.in`, `2.in`, ...时：

In the configuration file, a file group line looks like this,

when the only output file is `0.out` and there are multiple input files like `1.in`, `2.in`, ...:

```
File 0.out 1.luyre 2.luyre
```

## 提示信息翻译文件Prompt message translation file

提示信息翻译文件使用后缀`.lang`。

Translation files for prompts use the `.lang` extension.

对于每行，有固定格式，对于编号A1001，有替换参数{1}、{2}：

```
# 中文，注意使用半角符号
A1001=这是一个提示信息，参数为{1}和{2}。
```

For each line, there’s a fixed format. For the code A1001, there are replacement parameters {1} and {2}:

```
# English
A1001=This is a prompt message, with parameters {1} and {2}.
```

事实上，可以使用转义字符（例如`\033`，使得控制台有颜色）。

```
I1000=这里是\033[;36m{1}\033[0m!!!
```

In fact, you can use escape characters (to give the console some color with `\033`).

```
I1000=Here is \033[;36m{1}\033[0m!!!
```

你也可以使用注释，通过#符号。

You can also use comments with the # symbol.

```
# ...
```
