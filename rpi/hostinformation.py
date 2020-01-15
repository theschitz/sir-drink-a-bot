import socket
import platform
import uuid
import re

class Host:
    def __init__(self, ip_addr: str = None):
        self.host_name = socket.gethostname()
        self.host_ip = socket.gethostbyname(self.host_name)
        self.os: str = None
        self.MAC_addr: str = None

        if ip_addr is None:
            self.os = platform.system()
            self.MAC_addr = self.get_host_mac_address()

    def __repr__(self):
        return '{self.__class__.__name__}(ip_addr={self.host_ip})'.format(self=self)
    
    def __str__(self):
        return '{self.host_name} {self.host_ip} [{self.MAC_addr}] {self.os}'.format(self=self)

    @staticmethod
    def get_host_mac_address() -> str:        
        return ':'.join(re.findall('..', '%012x' % uuid.getnode()))


if __name__ == "__main__":
    host = Host()
    print(host)
    print(repr(host))


    