### 求解表达式

表达式：

    a = max(b, c/2)

表达式树：

        =
      /   \
     a     max
          /   \
         b     /
              / \
             c   2


### 树形积累

1. 求值该组合式的各子表达式
2. 将其运算过程应用与相应实际参数(子表达式值)

对子表达式的递归求解可以到达基本表达式

1. 数的值为它表达的数值
2. 运算(符号)过程的值为运算过程
3. 变量符号的值为环境中关联与之一符号的数值

eval0和eval1本质上是相同的，都是采用后序遍历二叉树求解表达式。

不同处在于:

* eval0判断树结点`Tree.op`，并在不同分支进行操作
* eval1采用数据驱动的方式，将操作函数`void (*op)(Tree *)`以操作类型`Tree.op`为键存入表`void (*optab[])(Tree *)`中，求值时不进行判断，直接使用`(*optab[t->op])(t)`

如果将`a = max(b, c/2)`看作一种程序语言的源代码的话，我们此时直接用C语言解释执行了这种程序。

### 虚拟机模式执行

eval2与eval0、eval1完全不同，eval2利用`generate`将表达式树生成操作序列存入`Code`类型的数组中，在`eval`函数中利用`stack`保存中间变量，最后求得结果

`a = max(b, c/2)`翻译为操作序列(code数组)为：

    pushsymop
    b
    pushsymop
    c
    pushop
    2
    divop
    maxop
    sotresymop
    a

此时code数组中的内容就像是虚拟机的指令流，而且我们实现了`eval`求解此指令流。

我们完全可以用值100，101，110...代替函数指针`pushsymop`,`pushsymop`,`divop`等，将code数组的内容当作虚拟指令保存为文件，然后读取文件将数值100，101，110...替换为函数指针，用`eval`求值。

也就是说有如下对应关系：

源代码： a = max(b, c/2)

编译器： generate函数

虚拟指令：

    pushsymop
    b
    pushsymop
    c
    pushop
    2
    divop
    maxop
    sotresymop
    a

解释器： eval函数
