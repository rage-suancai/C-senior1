C语言高级特性

前面我们了解了C语言的相关基础内容 我们来看看C语言的高级部分 这一章的学习难度会比较大 尤其是指针 因为需要理解计算机内存模型 所以说是很多初学者的噩梦

函数

其实函数我们在一开始就在使用了:

                    int main() { // 这是定义函数
                        ...
                    }

我们程序的入口点就是main函数 我们只需要将我们的程序代码编写到主函数中就可以运行了 不过这个函数只是由我们来定义 而不是我们自己来来调用
当然 除了主函数之外我们一直在使用的printf也是一个函数 不过这个函数是标准库中已经实现好了的 现在是我们在调用这个函数:

                    printf("Fuck World"); // 直接通过 函数名称(参数...)的形式调用函数

那么 函数的具体定义是什么呢?

    函数是完成特定任务的独立程序代码单元

其实简单来说 函数时为了完成某件任务而生的 可能我们要完成某个任务并不是一行代码就可以搞定的 但是现在可能遇到这种情况:

                    #include <stdio.h>

                    int main() {
                        int a = 10;
                        printf("H"); // 比如下面这三个行代码就是我们要做的任务
                        printf("A");
                        a += 10;

                        if (a > 20) {
                            printf("H"); // 这里我们还需要执行这个任务
                            printf("A");
                            a += 10;
                        }

                        switch (a) {
                            case 30:
                                printf("H"); // 这里又要执行这个任务
                                printf("A");
                                a += 10;
                        }
                    }

我们每次要做这个任务时 都要完完整整地将任务的每一行代码都写下来 如果我们的程序中多处都需要执行这个任务
每个地方都完整地写一遍 实在是太臃肿了 有没有一种更好的办法能优化我们的代码呢?

这时我们就可以考虑使用函数了 我们可以将我们的程序逻辑代码全部编写到函数中 当我们执行函数时
实际上执行的就是函数中的全部内容 也就是按照我们制定的规则执行对应的任务 每次需要做这个任务时只需要调用函数即可

我们来看看 如何创建和使用函数

创建和使用函数

首先我们来看看如何创建一个函数 其实创建一个函数是很简单的 样式如下:

    返回值类型 函数名称([函数参数...]);

其中函数名称也是有要求的 并不是所有的字符都可以用作函数名称 它的命名规则与变量的命名规则基本一致 所以这里就不一一列出了

函数不仅仅需要完成我们的任务 可能某些函数还需要告诉我们结果 比如我们之前认识的getchar函数 这个函数实际上返回了一个int值作为结果
(也就是我们输入的字符) 我们同样可以将函数返回的结果赋值给变量或是参与运算等等

当然如果我们的函数只需要完成任务 不需要告诉我们结果 返回值类型可以写成void表示为空

函数参数我们放在下一小节中讲解 所以这里我们不使用任何参数 所以这里也将参数设定为void表示没有参数(当然为了方便 我们也可以直接什么都不写)

                    #include <stdio.h>

                    void test(void); // 定义函数原型 因为C语言是从上往下的 所以如果要在下面的主函数中使用这个函数 一定要定义到它的上面

                    int main() {

                    }

                    void test(void) { // 函数具体定义 添加一个花括号并在其中编写程序代码 就和我们之前在main中编写一样
                        printf("我是测试函数");
                    }

或者直接在上方写上函数的具体定义:

                    #include <stdio.h>

                    void test(void) { // 函数具体定义 添加一个花括号并在其中编写程序代码 就和我们之前在main中编写一样
                        printf("我是测试函数");
                    }

                    int main() {


                    }

那么现在我们将函数定义好之后 该如何去使用呢?

                    int main() {
                        test(); // 这里我们只需要使用 函数名称(); 就可以调用函数了
                        printf("Fuck World");
                    }

                    我是测试函数
                    进程已结束,退出代码0

这样 我们就可以很好地解决上面的代码复用性的问题 我们只需要将会重复使用的逻辑代码定义到函数中
当我们需要执行时 直接调用编写好的函数就可以了 这样是不是简单多了?

                    int main() {
                        int a = 10;

                        test(); // 多次使用的情况下 函数会让我们的程序简单很多

                        if (a > 20) test();

                        switch (a) {
                            case 30:
                                test();
                        }
                    }

当然函数除了可以实现代码的复用之外 也可以优化我们的程序 让我们的代码写得更有层次感 我们的程序可能会有很多很多的功能 需要写很多的代码
但是谁愿意去看一个几百行上千行的main函数呢? 我们可以将每个功能都写到一个对应的函数中 这样就可以大大减少main函数中的代码量了

                    int main() {
                        func1(); // 直接把多行代码写入到函数中 在main中调用对应的函数 这样就能够大幅度减少代码量
                        func2();
                        func3();
                    }

而我们从一开始就在编写main函数实际上是一种比较特殊的函数 C语言规定程序一律从主函数开始执行 所以这也是为什么我们一定要写成int main()的形式