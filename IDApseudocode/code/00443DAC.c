void __fastcall dhcp_list_buf(int a1, int a2, int a3)
{
  _DWORD *v6; // $v0
  _DWORD *v7; // $s7
  _DWORD *v8; // $s0
  int v9; // $a2
  int v10; // $s6
  int v11; // $s1
  const char *v12; // $fp
  const char *v13; // $v0
  char v14[32]; // [sp+10h] [-50h] BYREF
  uint32_t v15; // [sp+30h] [-30h]
  char *v16; // [sp+34h] [-2Ch]

  if ( a1 )
  {
    if ( a3 )
    {
      v16 = "a";
      _mem_malloc(0x100000, "dhcp_list_buf", 2949);
      v7 = v6;
      if ( v6 )
      {
        v8 = v6 + 6;
        *v6 = 5;
        v6[3] = 4;
        v6[1] = 0x100000;
        strlcpy(v6 + 6, a3, 64);
        if ( !jianhl_order_opt_fun(v7, v7[1], v9) && (int)v7[5] > 0 )
        {
          v10 = 0;
          if ( a2 >= 100 )
          {
            v11 = 0;
            do
            {
              v12 = (const char *)get_json_data(v8);
              v15 = ntohl(v8[16]);
              v13 = (const char *)MacToStr(v14, v8 + 17);
              ++v10;
              v11 += sprintf(
                       (char *)(a1 + v11),
                       "{\"n\":\"%s\",\"i\":%u,\"m\":\"%s\",\"t\":%lu},",
                       v12,
                       v15,
                       v13,
                       v8[24]);
              v8 += 25;
            }
            while ( v10 < v7[5] && a2 - v11 >= 100 );
          }
        }
        _mem_free(v7);
      }
    }
  }
}
// 443E28: variable 'v6' is possibly undefined
// 443E6C: variable 'v9' is possibly undefined
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

