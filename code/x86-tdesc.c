  set_tdesc_architecture (tdesc, is_x32 ? "i386:x64-32" : "i386:x86-64");

  if (is_linux)
    set_tdesc_osabi (tdesc, "GNU/Linux");

  long regnum = 0;

  if (is_x32)
    regnum = create_feature_i386_x32_core (tdesc, regnum);
  else
    regnum = create_feature_i386_64bit_core (tdesc, regnum);
  regnum = create_feature_i386_64bit_sse (tdesc, regnum);
  if (is_linux)
    regnum = create_feature_i386_64bit_linux (tdesc, regnum);
  regnum = create_feature_i386_64bit_segments (tdesc, regnum);
  if (xcr0 & X86_XSTATE_AVX)
    regnum = create_feature_i386_64bit_avx (tdesc, regnum);
  if ((xcr0 & X86_XSTATE_MPX) && !is_x32)
    regnum = create_feature_i386_64bit_mpx (tdesc, regnum);
  if (xcr0 & X86_XSTATE_AVX512)
    regnum = create_feature_i386_64bit_avx512 (tdesc, regnum);
  if ((xcr0 & X86_XSTATE_PKRU) && !is_x32)
    regnum = create_feature_i386_64bit_pkeys (tdesc, regnum);
