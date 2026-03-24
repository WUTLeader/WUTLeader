#include <time.h>
#include "tool.h"

// 将 time_t 类型转换为字符串，字符串格式为“年-月-日 时:分”
void timeToString(time_t t, char* pBuf) {
    struct tm timeInfo;  // 定义结构体变量，不是指针

    // 将 time_t 类型转化为 tm 类型（安全版本）
    errno_t err = localtime_s(&timeInfo, &t);

    if (err == 0) {
        // 将 tm 类型转化为字符串
        strftime(pBuf, 20, "%Y-%m-%d %H:%M", &timeInfo);
    }
    else {
        // 转换失败，写入错误信息
        printf(pBuf, "时间错误");
    }
}