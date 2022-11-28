int __fastcall upnp_data_timeout(_DWORD *a1)
{
  _DWORD *v1; // $s1
  int result; // $v0

  v1 = a1 + 49152;
  if ( (int)a1[51393] >= 5 || f_exists("/var/spool/upnp.js") )
  {
    a1[51388] = httpd_keep_alive_timeout;
    a1[51387] = jiffies_get() + 5000;
    add_timer(a1 + 51385);
    result = upnp_data_send((int)a1);
  }
  else
  {
    ++v1[2241];
    v1[2235] = jiffies_get() + 1000;
    v1[2237] = a1;
    v1[2236] = upnp_data_timeout;
    result = add_timer(a1 + 51385);
  }
  return result;
}
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

