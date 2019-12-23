# WangWangChat
### 项目简介

基于C++的聊天软件。包括PC客户端、Linux服务端。服务端可同时向多个客户端提供服务。客户端包括注册、登陆、好友/群列表展示、群聊、私聊等基本功能。本仓库包括：客户端源码、服务端源码、数据协议、客户端发行版、客户端流程图、服务端流程图以及开发日志

### 主要技术

服务端：使用epoll实现I/O复用从而为多客户端提供服务。同时使用MySQL类内嵌SQL语句从而实现对数据库的访问。

客户端：使用Qt开发，使用QTcpSocket类实现与服务端通信，使用QWidget、QGroupBox与QToolButton实现类似QQ好友列表

数据库：通过建立用户基本信息user_info、好友关系friend、群组关系group、群组基本信息group_info四张表实现对用户信息的存储、组织。

### 开发环境

- 客户端： Windows + Qt5
- 服务端：Linux + C++
- 数据库： MySQL8.0
- 数据交互协议：自定（具体见文档）

### 效果展示

登陆界面：

![1577110794905](E:\learn\comm\WangWangChat\效果图\1577110794905.png)

注册界面：

![1577110899465](E:\learn\comm\WangWangChat\效果图\1577110899465.png)

主界面：

![1577111020223](E:\learn\comm\WangWangChat\效果图\1577111020223.png)

私聊：

![1577111135330](E:\learn\comm\WangWangChat\效果图\1577111135330.png)

群聊：

![1577111380041](E:\learn\comm\WangWangChat\效果图\1577111380041.png)