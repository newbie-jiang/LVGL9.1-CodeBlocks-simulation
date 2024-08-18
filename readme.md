# 韦东山LVGL9学习文档



## 环境安装配置 

### 资料下载：

仓库：

```
git clone https://gitee.com/weidongshan/lvgl_100ask_course_v9.git
```

更新：

```
git pull origin master
```

### 安装code::Blocks

![image-20240818114808825](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818114808825.png)

### 更新编译工具链以支持LVGL9特性

- 安装目录下删除原编译工具链

![image-20240818121403537](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818121403537.png)

- 替换工具链

![image-20240818124416966](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818124416966.png)

- 编译找不到工具链解决 setting --> compiler setting

![image-20240818125324363](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818125324363.png)

### 解决编译报错

![image-20240818125814736](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818125814736.png)

setting --> compiler setting

![image-20240818130042765](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818130042765.png)

将此处设置为如下

![image-20240818130206002](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818130206002.png)



## 获取LVGL源码并添加到code::Blocks运行

### 下载LVGL的code::Blocks支持包

前言：百问网做了一个code::Blocks运行LVGL包，下载该源码之后导入对应lvgl对应的版本源码，直接打开code::Blocks即可运行

code::Blocks包下载：https://github.com/lvgl/lv_port_win_codeblocks

这里的版本对应着支持lvgl的版本，需要版本一致

![image-20240818140532877](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818140532877.png)

下载9.1版本的code::Blocks支持包

![image-20240818140700968](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818140700968.png)

### 下载9.1版本的lvgl源码

doc : https://github.com/lvgl/lvgl/blob/master/docs/README_zh.rst

获取源码

```
 https://github.com/lvgl/lvgl.git
```

注：直接clone之后需要切换到分支

![image-20240818133058115](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818133058115.png)

选取特定版本

![image-20240818134317529](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818134317529.png)

![image-20240818134342480](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818134342480.png)

### 将lvgl源码导入code::Blocks支持包

下载好了支持包以及lvgl源码如下

![image-20240818141746843](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818141746843.png)

- 目前支持包的lvgl库为空

![image-20240818141905148](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818141905148.png)

将lvgl的源码导入进来

![image-20240818141950422](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818141950422.png)

![image-20240818142027398](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818142027398.png)

打开项目

![image-20240818142119612](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818142119612.png)

重新构建编译并运行（若有报错获找不到编译器，参考环境安装配置小节）

![image-20240818142540719](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818142540719.png)

![image-20240818142450935](https://newbie-typora.oss-cn-shenzhen.aliyuncs.com/TyporaJPG/image-20240818142450935.png)
