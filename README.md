# Luyre

Luyre（玥语言），编译型编程语言，一个”面向语法“编程的尝试。

Compiled programming languages, an attempt at syntax-oriented programming.

> &#9888;还在设计，请等待。Still designing, please wait.

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
PS C:\Users\YourName> luyre.exe config.luyreby
```

如果需要，可以额外加上一个提示信息翻译文件，例如：`logbook.lang`。

If needed, you can also add an extra hint information translation file, for example: `logbook.lang`.

```
PS C:\Users\YourName> luyre.exe config.luyreby logbook.lang
```

## 配置文件Configuration file

配置文件使用后缀`.luyreby`。

Configuration files use the `.luyreby` extension.

```
&#9888;待续
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
