int __fastcall sub_47EB78(int a1)
{
  int v1; // $v0
  const char *v3; // $a1

  v1 = get_web_language_type(a1);
  if ( v1 == 1 )
  {
    v3 = "auth_org_en.htm";
    return org_html(a1, (int)v3);
  }
  if ( v1 != 99 )
  {
    v3 = "auth_org.htm";
    return org_html(a1, (int)v3);
  }
  return org_html(a1, (int)"auth_org_ft.htm");
}

