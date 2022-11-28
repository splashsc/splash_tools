int __fastcall httpd_unix_send_to_ac_server(void *buf, size_t a2)
{
  struct sockaddr addr[7]; // [sp+20h] [-70h] BYREF

  addr[0].sa_family = 1;
  strcpy(addr[0].sa_data, "/tmp/ac_server/ac_local.sock");
  return -(a2 != sendto(gl_httpd_unix_fd, buf, a2, 0, addr, 0x6Eu));
}
// 66B5F0: using guessed type int gl_httpd_unix_fd;

