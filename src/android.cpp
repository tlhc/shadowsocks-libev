#define LOG_TAG "shadowsocks"

#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "android.h"

#define LOGI(...) do { __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__); } while(0)
#define LOGW(...) do { __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__); } while(0)
#define LOGE(...) do { __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__); } while(0)

#define NEW_SOCKET  "new_socket"
#define FREE_SOCKET "free_socket"
#define BUF_LEN 256

static int open_local_socket(char *path)
{
    struct sockaddr_un addr;
    socklen_t len;

    /* use abstract name space for socket path */
    addr.sun_family = AF_LOCAL;
    addr.sun_path[0] = '\0';
    strcpy(&addr.sun_path[1], path);
    len = offsetof(struct sockaddr_un, sun_path) + 1 + strlen(&addr.sun_path[1]);

    sk = socket(PF_LOCAL, SOCK_STREAM, 0);
    if (sk < 0) {
        err = errno;
        LOGE("%s: cannot open socket: %s (%d)\n", LOG_TAG, strerror(err), err);
        errno = err;
        return -1;
    }

    if (connect(sk, (struct sockaddr *) &addr, len) < 0) {
        err = errno;
        LOGE("%s: connect() failed: %s (%d)\n", LOG_TAG, strerror(err), err);
        close(sk);
        errno = err;
        return -1;
    }

    return sk;
}

int new_protected_socket()
{
    int fd = open_local_socket(NEW_SOCKET);
    char buffer[BUF_LEN]

    while (1)
    {
        int r = read(fd, buffer, BUF_LEN);
        if (r == -1)
        {
            if (errno == EINTR)
                continue;
            else
                return -1;
        }
        else
        {
            break;
        }
    }

    close(fd);

    return atoi(buffer);
}

void free_protected_socket(int fd)
{
    int fd = open_local_socket(FREE_SOCKET);

    char buffer[BUF_LEN]
    sprintf(buffer, "%d", fd);

    while (1)
    {
        int r = write(fd, buffer, strlen(buffer));
        if (r == -1)
        {
            if (errno == EINTR)
                continue;
            else
                return;
        }
        else
        {
            break;
        }
    }

    close(fd);
}
