int __fastcall time_group_is_used(const char *a1)
{
  void *v2; // $v0
  void *v3; // $s0
  int v4; // $v0
  int v6; // $v0
  bool v7; // dc
  int v8; // $v0
  int v9; // [sp+20h] [-Ch]

  _mem_malloc(0x200000, "time_group_is_used", 793);
  v3 = v2;
  if ( v2 )
  {
    v4 = mrprot_rule_check_used_group((int)a1, 1, v2, 0x200000u, 0);
    if ( !v4 )
    {
      v4 = macfilter_rule_check_used_group(a1, v3, 0x200000u, 0);
      if ( !v4 )
      {
        v4 = ddos_rule_check_used_group((int)a1, 1, v3, 0x200000u, 0);
        if ( !v4 )
        {
          v4 = xwgl_rule_check_used_group((int)a1, 1, v3, 0x200000u, 0);
          if ( !v4 )
          {
            v4 = url_rule_check_used_group((int)a1, 1, v3, 0x200000u, 0);
            if ( !v4 )
            {
              v4 = qq_rule_check_used_group(a1, v3, 0x200000u, 0);
              if ( !v4 )
              {
                v4 = qos_rule_check_used_group((int)&off_645B94, (int)a1, 1, (int)v3, 0x200000u, 0);
                if ( !v4 )
                {
                  v6 = qos_rule_check_used_group((int)"xz", (int)a1, 1, (int)v3, 0x200000u, 0);
                  v7 = v6 == 0;
                  v4 = v6 + 1;
                  if ( v7 )
                  {
                    v8 = qos_rule_check_used_group((int)"bz", (int)a1, 1, (int)v3, 0x200000u, 0);
                    if ( v8 )
                      v4 = v8 + 2;
                    else
                      v4 = ctxz_rule_check_used_group((int)a1, 1, v3, 0x200000u, 0);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v4 = 0;
  }
  v9 = v4;
  _mem_free(v3);
  return v9;
}
// 465140: variable 'v2' is possibly undefined
// 645B94: using guessed type void *off_645B94;

