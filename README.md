> &#9888;代码还在写，现在还没写到词法分析器，好伤心555\~
> 
> The code is still being written, and I haven't gotten to the lexer yet. So sad 555\~

[最新代码仓库Latest code repository](https://github.com/Ziou-Seisy/Luyre/tree/Framework)

# Luyre（玥语言）

Luyre（玥语言），编译型编程语言，一个“面向语法”编程的尝试。

Luyre: A compiled programming language, which is an attempt at syntax-oriented programming.

# 面向语法编程（GmOP）Grammar-oriented programming

面向语法编程是一种新的编程范式的尝试，是试图作为编程范式的大统一理论的试验。

Grammar-oriented programming is an attempt at a new programming paradigm, trying to serve as an experimental theory for a unified programming paradigm.

## 浅谈已有的编程范式A Brief Talk on Existing Programming Paradigms

编程范式是一类编程风格或方法，其遵循一系列特定的概念、原则和实践。

A programming paradigm is a basic style or approach to programming that follows a set of specific concepts, principles, and practices. 

常规的编程范式包括： Common programming paradigms include: 

### 指令式编程|命令式编程 IP:Imperative programming

> 在一定程度上To some extent：C、C++、Java、Python、Minecraft Command Block

指令式编程：要谁去干什么。

A series of steps that change the program's state.

支持语句形式：Supported statement forms:

```
result = expression
while(condition){ doing }
if(condition){ doing }else{ doing_else }
def func(arg_list){ doing; return ret }; func(arg_expression)
```

### 声明式编程 DP:Declarative programming

声明式编程：要什么。

Focus on expressing logic and functionality, without clearly describing the control flow.

#### 函数式编程 FP:Functional programming

> 在一定程度上To some extent：Haskell、Lisp、Erlang、JavaScript、Python、Scala

 函数式编程：万物皆可函数。

View computation as the evaluation of mathematical functions and emphasize using immutable data and declarative expressions.

支持语句形式：Supported statement forms:

```
func = (arg_list)=>{ doing; return ret }
def loop(arg_list){ doing; return loop(arg_expression)}
array.map(callbackFn); array.reduce(callbackFn, initialValue)
result = (Pip(val) | func).result()
def curry(val){ return (x)=>func(val,x) }
def higherFunc(func,val){ return func(val) }
```

#### 约束式编程 CP:Constraint Programming

> 在一定程度上To some extent：MiniZinc、Groubi、Python with CPMpy、Google OR-Tools、Microsoft Z3-Solver、IBM CPLEX

约束式编程：列方程求解。

The relationships between variables are described in constraints, which define the range of solutions for the problem. These constraints are then used by the application to solve it, so that each variable gets a value and as many constraints as possible are satisfied.

支持语句形式：Supported statement forms:

```
mod.add(Constraints)
status = solver.solve(mod)
```
#### 逻辑式编程

> 在一定程度上 To some extent：Prolog

逻辑式编程：声明、提问。

State a relationship and ask questions about it.

支持语句形式：Supported statement forms:

```
Fact(val_expression)
Rule(arg_list) :- expression
?- Rule(arg_expression)
```

#### 领域专属语言 DSL:Domain-specific language

> 在一定程度上 To some extent：yacc（语法分析器）、Make（编译说明）、Puppet（管理配置）、正则表达式、SQL（Select queries等）
> 
> yacc (parser), Make (build instruction), Puppet (configuration management), regular expressions, SQL (Select queries, etc.)

> 此外，很多文本标记语言Besides, a lot of markup languages：HTML、MXML、XAML、XSLT、MarkDown、[FNP_LightML](https://github.com/Ziou-Seisy/FNP_LightML)、CSS、json

支持语句形式：Supported statement forms:

```
<Tag option="val"></Tag>
Option arg_expression
"key":"val"
```

### 面向对象编程（OOP）

面向对象编程：把数据和方法放在一起。

Abstract things into objects, give objects attributes and methods, and let each object execute its own methods to solve the problem.

支持语句形式：Supported statement forms:

```
class OBJ { public: Type val; def func(arg_list){}; OBJ(arg_list){} }; OBJ obj {arg_exp};
obj.func(arg_exp); func(obj.val)
class SUB_OBJ : protected OBJ {}; SUB_OBJ sub;
OBJ& p = sub;
```

### 面向切面编程（AOP）

### 反应式编程

### 范型编程

### 并发编程

### 面向语法糖编程

### 面向语法编程

面向语法编程：以上全部

