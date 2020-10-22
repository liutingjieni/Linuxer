/*************************************************************************
	> File Name: conn.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月19日 星期一 18时53分41秒
 ************************************************************************/

#ifndef _CONN_H
#define _CONN_H
#include "buffer.h"

//保存客户端

//每个连接对应一个conn
class conn {
public:
    conn() : buffer_(new buffer) {  }
    int read();
    int get_fd()
    {
        return fd;
    }
private:
    int fd;
    struct sockaddr_in addr;
    static socklen_t len;
    std::shared_ptr<buffer> buffer_;
    int save_errno;
    friend class Socket;
    friend class Epoll;
};

int conn::read()
{
    buffer_->read_fd(fd, &save_errno);
    return save_errno;
}

socklen_t conn::len = sizeof(struct sockaddr_in);

//conn_list对应所有连接的信息
std::map<int, std::shared_ptr<conn>> conn_list;  //保存所有的连接信息

#endif