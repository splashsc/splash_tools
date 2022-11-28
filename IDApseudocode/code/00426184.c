int __fastcall httpd_send_logs_file(int a1)
{
  char *v2; // $v0
  void *v3; // $s0
  size_t v4; // $v0
  char v6[256]; // [sp+18h] [-1A0h] BYREF
  struct stat v7; // [sp+118h] [-A0h] BYREF

  strcpy(v6, "/tmp/logs/");
  memset(&v6[11], 0, 0xF5u);
  v2 = strstr(*(const char **)(a1 + 44), "/logs/");
  v3 = v2 + 6;
  if ( !v2 )
    return -1;
  v4 = strlen(v2 + 6);
  if ( v4 >= 0xC9 )
    return -1;
  memcpy(&v6[10], v3, v4 + 1);
  if ( stat(v6, &v7) )
  {
    unescape(v6);
    if ( stat(v6, &v7) )
      return -1;
  }
  if ( (v7.st_uid & 0xF000) == 0x4000 )
    return -1;
  httpd_send_big_file(a1, (int)v6, v7.st_atim.tv_sec);
  return 0;
}

