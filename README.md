# LearnSFML

运行代码前确保**本地**已经配置好 **SFML** 环境，配置过程参照[官网](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php)

## 如何使用

进入到相应的项目文件下，可以看到基本的目录结构为

```
- blog*
    - src
    - build
    - CmakeList.txt
    - README.md
    - ...
```

进入 `build` 目录，运行以下命令:

```shell
$ cmake ..
$ make
```

接着就可以看到当前目录下生成的可执行文件 `blog*`