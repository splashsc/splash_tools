ssize_t __fastcall shenji_send_to_ctrl(const char *a1)
{
  int v2; // $v0
  uint16_t v3; // $v0
  unsigned int v4; // $s1
  int v5; // $v0
  ssize_t result; // $v0
  char v7[1024]; // [sp+20h] [-414h] BYREF
  struct sockaddr addr; // [sp+420h] [-14h] BYREF

  memset(v7, 0, sizeof(v7));
  addr.sa_family = 2;
  v2 = jhl_nv_get_def("sj_udp_port");
  v3 = J_atoi(v2);
  *(_WORD *)addr.sa_data = htons(v3);
  *(_DWORD *)&addr.sa_data[2] = htonl(0);
  v4 = snprintf(v7, 1024, "{\"action\":\"%s\"}", a1);
  if ( v4 >= 0x400 )
    v4 = 1023;
  v5 = socket(2, 1, 0);
  if ( v5 == -1 )
    result = -1;
  else
    result = sendto(v5, v7, v4, 0, &addr, 0x10u);
  return result;
}
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

