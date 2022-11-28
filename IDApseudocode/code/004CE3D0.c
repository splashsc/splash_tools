int bind(int fd, const struct sockaddr *addr, socklen_t len)
{
  MEMORY[0](fd, addr, len);
  return cJSON_CreateObject();
}
// 4CE3E0: using guessed type int cJSON_CreateObject(void);

