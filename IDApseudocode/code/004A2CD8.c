int __fastcall dhcp_detect_list_data_timeout(_DWORD *a1)
{
  _DWORD *v1; // $s0
  int v2; // $v0
  int result; // $v0

  v1 = a1 + 49152;
  v2 = a1[51393];
  if ( v2 < 3 )
  {
    a1[51393] = v2 + 1;
    a1[51387] = jiffies_get() + 1000;
    v1[2237] = a1;
    v1[2236] = dhcp_detect_list_data_timeout;
    result = add_timer(a1 + 51385);
  }
  else
  {
    a1[51388] = httpd_keep_alive_timeout;
    a1[51387] = jiffies_get() + 5000;
    add_timer(a1 + 51385);
    result = dhcp_detect_list_data_send((int)a1);
  }
  return result;
}
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

