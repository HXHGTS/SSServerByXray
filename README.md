# shadowsocksServerByXray

基于Xray搭建的Shadowsocks脚本，请务必在MPLS/IPLC/IEPL内网环境下使用!!!

## 警告⚠：此技术仅限用于个人搭建游戏加速器使用！！！若用于其他违法目的，后果自负！！！

KVM/XEN/Vmware机器执行(CentOS7):

`yum install -y gcc wget && wget https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/shadowsocks.c -O shadowsocks.c && chmod +x shadowsocks.c && gcc -o xray shadowsocks.c && ./xray`

LXC/OVZ机器执行(CentOS7):

`yum install -y gcc wget && wget https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/shadowsocks_no_kernel_update.c -O shadowsocks.c && chmod +x shadowsocks.c && gcc -o xray shadowsocks.c && ./xray`

KVM/XEN/Vmware机器执行(CentOS8):

`yum install -y gcc wget && wget https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/shadowsocks_centos8.c -O shadowsocks.c && chmod +x shadowsocks.c && gcc -o xray shadowsocks.c && ./xray`

LXC/OVZ机器执行(CentOS8):

`yum install -y gcc wget && wget https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/shadowsocks_centos8.c -O shadowsocks.c && chmod +x shadowsocks.c && gcc -o xray shadowsocks.c && ./xray`

KVM/XEN/Vmware机器执行(Debian9/10):

`apt update && apt install -y build-essential wget && wget https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/shadowsocks_debian10.c -O shadowsocks.c && chmod +x shadowsocks.c && gcc -o xray shadowsocks.c && ./xray`

KVM/XEN/Vmware机器执行(Debian11):

`apt update && apt install -y build-essential wget && wget https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/shadowsocks_debian11.c -O shadowsocks.c && chmod +x shadowsocks.c && gcc -o xray shadowsocks.c && ./xray`

第一次点击安装后会自动升级系统内核并触发重启，重启后输入

`./xray`

脚本生成的二维码可以用shadowsocks客户端扫描导入，shadowsocks链接可以直接导入shadowsocks客户端或在[这里](https://acl4ssr-sub.github.io/)生成Clash链接以导入Clash

### 安装前准备：

1.脚本仅支持CentOS7/CentOS8/Debian9/Debian10系统

2.脚本执行需要root权限登录系统，AWS等特殊机型打开root权限方法[看这里](https://hxhgts.github.io/AWSECSRoot/)

3.请在服务器后台防火墙放行tcp 8444端口
