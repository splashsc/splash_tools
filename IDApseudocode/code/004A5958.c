int __fastcall sub_4A5958(_DWORD *a1)
{
  const char *v2; // $v0
  int result; // $v0

  unlink("/var/spool/upnp.js");
  v2 = (const char *)nvram_get("upnp_enable");
  if ( v2 && !strcmp(v2, "1") && !killall("upnp", 17) )
  {
    a1[51393] = 0;
    upnp_data_timeout(a1);
    result = 0;
  }
  else
  {
    upnp_data_send((int)a1);
    result = 0;
  }
  return result;
}
// 6A8178: using guessed type int __fastcall killall(_DWORD, _DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

