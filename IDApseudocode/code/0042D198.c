int __fastcall httpd_tggl_init(int a1, uint16_t a2, int a3)
{
  int v5; // $v0
  uint16_t v6; // $v0
  uint32_t v7; // $t1
  uint32_t v8; // $t0
  uint32_t v9; // $v1
  int v10; // $s0
  int result; // $v0
  struct sockaddr v12; // [sp+20h] [-28h] BYREF
  uint32_t v13; // [sp+30h] [-18h]
  uint32_t v14; // [sp+34h] [-14h]
  int v15; // [sp+38h] [-10h]
  int v16; // [sp+3Ch] [-Ch] BYREF
  int v17; // [sp+40h] [-8h]

  v16 = 1;
  v5 = socket(10, 2, 0);
  dword_667720 = v5;
  if ( v5 == -1 )
  {
    perror("socket");
    result = -1;
  }
  else
  {
    setnonblocking(v5);
    *(_DWORD *)&v12.sa_data[2] = 0;
    *(_DWORD *)&v12.sa_data[6] = 0;
    *(_DWORD *)&v12.sa_data[10] = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    *(_DWORD *)&v12.sa_family = 10;
    v6 = htons(a2);
    v7 = in6addr_any.in6_u.u6_addr32[1];
    v8 = in6addr_any.in6_u.u6_addr32[2];
    v9 = in6addr_any.in6_u.u6_addr32[3];
    v17 = dword_667720;
    *(_DWORD *)&v12.sa_data[6] = in6addr_any.in6_u.u6_addr32[0];
    *(_DWORD *)&v12.sa_data[10] = v7;
    v13 = v8;
    v14 = v9;
    v16 = 1;
    *(_WORD *)v12.sa_data = v6;
    setsockopt(dword_667720, 0xFFFF, 4, &v16, 4u);
    v10 = 10;
    if ( bind(dword_667720, &v12, 0x1Cu) == -1 )
    {
      while ( 1 )
      {
        --v10;
        if ( bind(dword_667720, &v12, 0x1Cu) != -1 )
          break;
        if ( !v10 )
        {
          v17 = -1;
          perror("bind");
          return v17;
        }
      }
    }
    if ( listen(dword_667720, a3) == -1 )
    {
      v17 = -1;
      perror("listen");
      result = v17;
    }
    else
    {
      if ( debug_level > 0 )
        printf("%s:%d httpd_tggl_init ok\n", "httpd_tggl_init", 1137);
      result = 0;
    }
  }
  return result;
}
// 667720: using guessed type int dword_667720;
// 67D0BC: using guessed type int debug_level;

