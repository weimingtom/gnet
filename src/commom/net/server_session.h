#pragma once
#include "../pre_header.h"
#include "asio/asio.hpp"
#include "net_packet.hpp"
#include "io_service_holder.h"
#include "base_session.hpp"

namespace gnet {
#define BUF_READ_SIZE (8*1024)
class server_session_mgr;
class server_session : public base_session<server_session>
{
private:
	std::shared_ptr<server_session_mgr>	m_server_session_mgr_sp;
	std::function<void(net_packet*, uint32)>	m_server_session_msg_handler;
public:
	server_session(uint32 timeout);
	void post_net_packet_handler();
	void timeout_check();
	void set_server_session_mgr(std::shared_ptr<server_session_mgr>& server_session_mgr_sp);
	void stop();
	void set_server_session_msg_handler(std::function<void(net_packet*, uint32)>& handler);
};

};

