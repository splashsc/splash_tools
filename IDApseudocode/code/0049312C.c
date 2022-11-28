int __fastcall dns_more_get_dnstype_item_list_id(int a1)
{
  int v2; // $a2
  int result; // $v0
  int v4[25600]; // [sp+18h] [-19000h] BYREF

  memset(v4, 0, sizeof(v4));
  v4[0] = 58;
  v4[3] = 21;
  v4[1] = 102400;
  BYTE2(v4[21]) = J_atoi(a1);
  if ( jianhl_order_opt_fun(v4, v4[1], v2) )
    result = 0;
  else
    result = v4[5];
  return result;
}
// 4931B4: variable 'v2' is possibly undefined
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

