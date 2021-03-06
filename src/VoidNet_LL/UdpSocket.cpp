#include "VoidNet_LL/UdpSocket.hpp"

namespace std::net
{
	UdpSocket::UdpSocket(Socket * soc)
	{
		m_socket = unique_ptr<Socket>(soc); // will this work
	}

	UdpSocket::UdpSocket(AddressFamily af)
	{
		m_socket = make_unique<Socket>(SocketType::Datagram, af);
	}

	bool UdpSocket::Bind(const IPAddress & addr)
	{
		return m_socket->Bind(addr);
	}

	bool UdpSocket::SendTo(const byte * data, int32_t count, int32_t & sent, const IPAddress & addrDest)
	{
		return m_socket->SendTo(data, count, sent, addrDest);
	}

	bool UdpSocket::RecvFrom(byte * data, int32_t size, int32_t & read, IPAddress & srcAddr, SocketReceiveFlags flags)
	{
		return m_socket->RecvFrom(data, size, read, srcAddr, flags);
	}

	bool UdpSocket::GetPeerAddress(IPAddress & outAddr)
	{
		return m_socket->GetPeerAddress(outAddr);
	}

	bool UdpSocket::JoinMulticastGroup(const IPAddress & addrStr)
	{
		return m_socket->JoinMulticastGroup(addrStr);
	}

	bool UdpSocket::LeaveMulticastGroup(const IPAddress & addrStr)
	{
		return m_socket->LeaveMulticastGroup(addrStr);
	}

	bool UdpSocket::SetMulticastLoopback(bool loopback)
	{
		return m_socket->SetMulticastLoopback(loopback);
	}

	bool UdpSocket::SetMulticastTtl(byte timeToLive)
	{
		return m_socket->SetMulticastTtl(timeToLive);
	}

	uint32_t UdpSocket::GetPort()
	{
		return m_socket->GetPort();
	}

	bool UdpSocket::SetReuseAddr(bool allowReuse)
	{
		return m_socket->SetReuseAddr(allowReuse);
	}
}
