int __fastcall sub_4260D4(int a1)
{
  char v3[256]; // [sp+18h] [-1A4h] BYREF
  struct stat v4; // [sp+118h] [-A4h] BYREF

  snprintf(v3, 256, "/tmp/wxwifi/%s", (const char *)(*(_DWORD *)(a1 + 44) + 16));
  if ( stat(v3, &v4) || (v4.st_uid & 0xF000) == 0x4000 )
    return -1;
  httpd_send_big_file(a1, (int)v3, v4.st_atim.tv_sec);
  return 0;
}

