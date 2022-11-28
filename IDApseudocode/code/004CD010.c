int accept(int fd, struct sockaddr *addr, socklen_t *addr_len)
{
  MEMORY[0](fd, addr, addr_len);
  return fork();
}

