void *sdwan_get_ac_dev_list()
{
  int v0; // $v0
  int v1; // $s3
  const char *v2; // $v1
  char *v3; // $v0
  int v4; // $a0
  int v5; // $a1
  int v6; // $a0
  size_t v7; // $v0
  void *v8; // $s0
  int v10; // $s1
  void *v11; // $v0
  int v12[25600]; // [sp+20h] [-19560h] BYREF
  uint32_t v13; // [sp+19020h] [-560h] BYREF
  uint32_t v14; // [sp+19024h] [-55Ch]
  struct sockaddr v15; // [sp+19420h] [-160h] BYREF
  struct sockaddr v16[7]; // [sp+19490h] [-F0h] BYREF
  struct sockaddr v17[7]; // [sp+19500h] [-80h] BYREF
  _DWORD v18[2]; // [sp+19570h] [-10h] BYREF
  socklen_t addr_len[2]; // [sp+19578h] [-8h] BYREF

  strcpy(v17[0].sa_data, "/tmp/ac_server/ac_local.sock");
  addr_len[0] = 110;
  v17[0].sa_family = 1;
  v16[0].sa_family = 1;
  v18[0] = 1;
  v18[1] = 0;
  v0 = socket(1, 1, 0);
  if ( v0 < 0 )
    return 0;
  v1 = v0;
  create_dir2("/tmp/ac_server/jhttpd_local.sock");
  unlink("/tmp/ac_server/jhttpd_local.sock");
  v2 = "/tmp/ac_server/jhttpd_local.sock";
  v3 = v16[0].sa_data;
  do
  {
    v4 = *((_DWORD *)v2 + 1);
    *(_DWORD *)v3 = *(_DWORD *)v2;
    *((_DWORD *)v3 + 1) = v4;
    v5 = *((_DWORD *)v2 + 2);
    *((_DWORD *)v3 + 1) = v4;
    *((_DWORD *)v3 + 2) = v5;
    v6 = *((_DWORD *)v2 + 3);
    *((_DWORD *)v3 + 2) = v5;
    *((_DWORD *)v3 + 3) = v6;
    v2 += 16;
    *((_DWORD *)v3 + 3) = v6;
    v3 += 16;
  }
  while ( v2 != "" );
  *v3 = *v2;
  if ( bind(v1, v16, 0x6Eu) < 0 )
    return 0;
  setsockopt(v1, 0xFFFF, 4101, v18, 8u);
  setsockopt(v1, 0xFFFF, 4102, v18, 8u);
  v13 = htonl(0xFu);
  v14 = htonl(8u);
  v7 = ntohl(v14);
  sendto(v1, &v13, v7, 0, v17, 0x6Eu);
  usleep(0x186A0u);
  if ( recvfrom(v1, v12, 0x19000u, 0, &v15, addr_len) > 0 && v12[0] )
  {
    v10 = 20 * v12[0] + 4;
    _mem_malloc(v10, "sdwan_get_ac_dev_list", 1083);
    v8 = v11;
    if ( v11 )
      memcpy(v11, v12, v10);
  }
  else
  {
    v8 = 0;
  }
  close(v1);
  return v8;
}
// 438B4C: variable 'v11' is possibly undefined
// 6A8584: using guessed type int __fastcall create_dir2(_DWORD);

