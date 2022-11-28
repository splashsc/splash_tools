void __fastcall sub_421B30(_DWORD *a1, const char *a2)
{
  const char *v4; // $s1

  if ( a1[51397] == 3 && (!strcmp(a2, "index.htm") || !strcmp(a2, "index.html")) )
  {
    if ( (a1[8] & 0x400) == 0
      || (v4 = (const char *)a1[51380], strcmp(v4, gl_referer))
      && strncmp(v4, gl_referer2[0], 0x18u)
      && strncmp(v4, gl_referer3[0], 0x18u) )
    {
      httpd_send_referer((int)a1);
    }
  }
}
// 666188: using guessed type char *gl_referer3[3];
// 66618C: using guessed type char *gl_referer2[2];
// 666190: using guessed type char *gl_referer;

