int __fastcall sq_file_get_fun(char *a1)
{
  int v2; // $a2
  int result; // $v0
  unsigned int v4; // $s1
  int v5; // $v0
  unsigned int v6; // $hi
  unsigned int v7; // $s1
  unsigned int v8; // $lo
  unsigned int v9; // $hi
  int v10[257]; // [sp+50h] [-404h] BYREF

  memset(v10, 0, 0x400u);
  v10[0] = 6;
  v10[3] = 1;
  v10[1] = 1024;
  if ( jianhl_order_opt_fun(v10, 1024, v2) || (v4 = v10[54], v5 = sq_file_get_max_wan(), !v10[5]) )
  {
    result = 3;
    *(_DWORD *)a1 = 8200315;
  }
  else
  {
    v6 = v4 % 0x174;
    v7 = v4 / 0x174 + 1970;
    v8 = v6 / 0x1F;
    v9 = v6 % 0x1F;
    if ( v10[16] == 40 )
      result = sprintf(
                 a1,
                 "{\"xlh\":\"%s\",\"jb_s\":\"0\",\"jb\":\"%s\",\"dtime\":%u,\"state\":%u,\"hi_num\":%u,\"wan_num\":%d,\"s"
                 "id_pre\":\"%s\",\"sid_mid\":\"%s\",\"sid_end\":\"%s\",\"sb_dtime\":\"%04d-%02d-%02d\",\"test\":%d,\"tti"
                 "me\":%u,\"ttype\":%d}",
                 (const char *)&v10[24],
                 byte_64D9E0,
                 v10[15],
                 v10[5],
                 v10[48],
                 v5,
                 (const char *)&v10[57],
                 (const char *)&v10[62],
                 (const char *)&v10[66],
                 v7,
                 v8 + 1,
                 v9 + 1,
                 0,
                 0,
                 0);
    else
      result = sprintf(
                 a1,
                 "{\"xlh\":\"%s\",\"jb_s\":\"1\",\"jb\":\"%u\",\"dtime\":%u,\"state\":%u,\"hi_num\":%u,\"wan_num\":%d,\"s"
                 "id_pre\":\"%s\",\"sid_mid\":\"%s\",\"sid_end\":\"%s\",\"sb_dtime\":\"%04d-%02d-%02d\",\"test\":%d,\"tti"
                 "me\":%u,\"ttype\":%d}",
                 (const char *)&v10[24],
                 v10[16] / 0xAu,
                 v10[15],
                 v10[5],
                 v10[48],
                 v5,
                 (const char *)&v10[57],
                 (const char *)&v10[62],
                 (const char *)&v10[66],
                 v7,
                 v8 + 1,
                 v9 + 1,
                 0,
                 0,
                 0);
  }
  return result;
}
// 4AE894: variable 'v2' is possibly undefined
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

