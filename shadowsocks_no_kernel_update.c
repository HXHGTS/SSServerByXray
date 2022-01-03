#include <stdio.h>
#include <stdlib.h>


FILE* config;
char passwd[30];
int mode;

int main(){
Menu:UI();
    system("clear");
    if (mode == 1) {
        install_xray();
        goto Menu;
    }
    else if (mode == 2) {
        system("systemctl stop xray");
        system("systemctl start xray");
        printf("正在检测xray运行状态，以下输出不为空则运行正常！\n");
        printf("---------------以下输出为绿色则xray运行正常-----------------\n");
        system("systemctl status xray -l");
        system("ss -lp | grep xray");
        printf("\n--------------------------------------------------------\n");
        goto Menu;
    }
    else if (mode == 3) {
        printf("shadowsocks链接:\n\n");
        system("cat /usr/local/etc/xray/shadowsocks.txt");
        printf("\n");
        goto Menu;
    }
    else if (mode == 4) {
        system("vi /usr/local/etc/xray/config.json");
        system("systemctl restart xray");
        printf("正在检测xray运行状态，以下输出不为空则运行正常！\n");
        printf("---------------以下输出为绿色则xray运行正常-----------------\n");
        system("systemctl status xray -l");
        system("ss -lp | grep xray");
        printf("\n--------------------------------------------------------\n");
        goto Menu;
    }
    else if (mode == 5) {
        printf("正在更新xray主程序. . .\n");
        system("systemctl stop xray");
        system("wget https://raw.githubusercontent.com/XTLS/Xray-install/master/install-release.sh -O install-release.sh");
        system("bash install-release.sh");
        system("rm -f install-release.sh");
        system("systemctl start xray");
        printf("xray主程序更新完成！\n");
        printf("正在检测xray运行状态，以下输出不为空则运行正常！\n");
        printf("---------------以下输出为绿色则xray运行正常-----------------\n");
        system("systemctl status xray -l");
        system("ss -lp | grep xray");
        printf("\n--------------------------------------------------------\n");
        goto Menu;
    }
    else if (mode == 6) {
        system("systemctl stop xray");
        system("systemctl disable xray");
        system("systemctl status xray");
        goto Menu;
    }
    else {
        exit(0);
    }
    return 0;
}

int UI() {
    printf("-----------------------------------------------------------\n");
    printf("----------------------xray安装工具-----------------------\n");
    printf("-----------------------------------------------------------\n");
    printf("----------------------当前Kernel版本-----------------------\n");
    system("uname -sr");
    printf("-----------------------------------------------------------\n");
    printf("1.安装xray\n2.运行xray\n3.显示配置\n4.修改xray配置\n5.更新xray\n6.关闭xray\n0.退出\n");
    printf("-----------------------------------------------------------\n");
    printf("请输入:");
    scanf("%d", &mode);
    return 0;
}

int install_xray() {
    KernelUpdate(); 
    system("setenforce 0");
    system("yum install -y bind-utils");
    printf("正在运行xray安装脚本. . .\n");
    system("wget https://cdn.jsdelivr.net/gh/XTLS/Xray-install/install-release.sh -O install-release.sh");
    system("chmod +x install-release.sh");
    system("bash install-release.sh");
    system("sleep 3");
    system("rm -rf install-release.sh");
    system("rm -rf TCPO.sh");
    printf("正在生成配置文件. . .\n");
    system("curl https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/config.json.1 > /usr/local/etc/xray/config.json");
    printf("正在生成强密码. . .\n");
    system("xray uuid > /usr/local/etc/xray/passwd.conf");
    config = fopen("/usr/local/etc/xray/passwd.conf", "r");
    fscanf(config, "%s",passwd);
    fclose(config);
    config = fopen("/usr/local/etc/xray/config.json", "a");
    fprintf(config, "                        \"password\": \"%s\",\n", passwd);
    fclose(config);
    system("curl https://raw.githubusercontent.com/HXHGTS/SSServerByXray/main/config.json.2 >> /usr/local/etc/xray/config.json");
    printf("正在启动xray并将xray写入开机引导项. . .\n");
    system("systemctl stop xray");
    system("systemctl enable xray && systemctl start xray");
    QRCodeGen();
    printf("正在检测xray运行状态，以下输出不为空则运行正常！\n");
    printf("---------------以下输出为绿色则xray运行正常-----------------\n");
    system("systemctl status xray -l");
    system("ss -lp | grep xray");
    printf("\n--------------------------------------------------------\n");
    printf("xray部署完成！\n");
    printf("\n\n");
    printf("shadowsocks链接:\n\n");
    system("cat /usr/local/etc/xray/shadowsocks.txt");
    return 0;
}

int QRCodeGen() {
    config = fopen("/usr/local/etc/xray/shadowsocks.txt", "w");
    fprintf(config, "ss://chacha20-ietf-poly1305:%s@127.0.0.1:8444\n",passwd);
    fclose(config);
    return 0;
}

int KernelUpdate() {
    system("curl -sSL https://cdn.jsdelivr.net/gh/HXHGTS/TCPOptimization/TCPO.sh | sh");
    return 0;
}
