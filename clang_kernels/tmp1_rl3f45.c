typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_64_512_9_4n1(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    float val0 = *(data2+ridx0);
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 512; ridx1++) {
      for (int ridx2 = 0; ridx2 < 9; ridx2++) {
        float4 val1 = *((float4*)(data1+(ridx0*36)+(ridx1*2304)+(ridx2<<2)));
        float alu0 = (val1[0]-val0);
        float alu1 = (val1[1]-val0);
        float alu2 = (val1[2]-val0);
        float alu3 = (val1[3]-val0);
        acc0 = (acc0+(alu0*alu0)+(alu1*alu1)+(alu2*alu2)+(alu3*alu3));
      }
    }
    *(data0+ridx0) = acc0;
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_16_4n9(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 16; ridx0++) {
    int alu0 = (ridx0<<2);
    float4 val0 = *((float4*)(data0+alu0));
    float4 val1 = *((float4*)(data1+alu0));
    *((float4*)(data0+alu0)) = (float4){((val0[0]*0.9f)+(val1[0]*5.425641622541265e-06f)),((val0[1]*0.9f)+(val1[1]*5.425641622541265e-06f)),((val0[2]*0.9f)+(val1[2]*5.425641622541265e-06f)),((val0[3]*0.9f)+(val1[3]*5.425641622541265e-06f))};
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_16_4n7(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 16; ridx0++) {
    int alu0 = (ridx0<<2);
    float4 val0 = *((float4*)(data1+alu0));
    *((float4*)(data0+alu0)) = (float4){__builtin_sqrtf((1/((val0[0]*5.425347262644209e-05f)+1e-05f))),__builtin_sqrtf((1/((val0[1]*5.425347262644209e-05f)+1e-05f))),__builtin_sqrtf((1/((val0[2]*5.425347262644209e-05f)+1e-05f))),__builtin_sqrtf((1/((val0[3]*5.425347262644209e-05f)+1e-05f)))};
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_512_64_3_3_2_2n2(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      for (int ridx2 = 0; ridx2 < 3; ridx2++) {
        int alu0 = ((ridx0*576)+(ridx1*9)+(ridx2*3));
        int alu1 = ((ridx0*2304)+(ridx1*36)+(ridx2*12));
        float val0 = *(data2+ridx1);
        float val1 = *(data3+ridx1);
        float val2 = *(data4+ridx1);
        float val3 = *(data5+ridx1);
        float2 val4 = *((float2*)(data1+alu1+4));
        float alu2 = (((val4[0]-val0)*val1*val2)+val3);
        float alu3 = (((val4[1]-val0)*val1*val2)+val3);
        float2 val5 = *((float2*)(data1+alu1+6));
        float alu4 = (((val5[0]-val0)*val1*val2)+val3);
        float alu5 = (((val5[1]-val0)*val1*val2)+val3);
        float4 val6 = *((float4*)(data1+alu1+8));
        float alu6 = (((val6[0]-val0)*val1*val2)+val3);
        float alu7 = (((val6[1]-val0)*val1*val2)+val3);
        float alu8 = (((val6[2]-val0)*val1*val2)+val3);
        float alu9 = (((val6[3]-val0)*val1*val2)+val3);
        float alu10 = ((alu2<alu8)?alu8:alu2);
        float alu11 = ((alu10<alu3)?alu3:alu10);
        *(data0+alu0+2) = ((alu11<alu9)?alu9:alu11);
        float4 val7 = *((float4*)(data1+alu1));
        float alu12 = (((val7[0]-val0)*val1*val2)+val3);
        float alu13 = (((val7[1]-val0)*val1*val2)+val3);
        float alu14 = (((val7[2]-val0)*val1*val2)+val3);
        float alu15 = (((val7[3]-val0)*val1*val2)+val3);
        float alu16 = ((alu12<alu4)?alu4:alu12);
        float alu17 = ((alu14<alu6)?alu6:alu14);
        float alu18 = ((alu16<alu13)?alu13:alu16);
        float alu19 = ((alu17<alu15)?alu15:alu17);
        *(data0+alu0+1) = ((alu19<alu7)?alu7:alu19);
        *(data0+alu0) = ((alu18<alu5)?alu5:alu18);
      }
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_512_64_3_3_2_2n3(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      for (int ridx2 = 0; ridx2 < 3; ridx2++) {
        int alu0 = ((ridx0*576)+(ridx1*9)+(ridx2*3));
        int alu1 = (alu0+1);
        int alu2 = (alu0+2);
        int alu3 = ((ridx0*2304)+(ridx1*36)+(ridx2*12));
        float val0 = *(data2+ridx1);
        float val1 = *(data3+ridx1);
        float val2 = *(data4+ridx1);
        float val3 = *(data5+ridx1);
        float val4 = *(data6+alu1);
        float val5 = *(data6+alu2);
        float val6 = *(data6+alu0);
        float2 val7 = *((float2*)(data1+alu3+4));
        float2 val8 = *((float2*)(data1+alu3+6));
        float4 val9 = *((float4*)(data1+alu3+8));
        *(data0+alu2) = ((float)((((((val7[0]-val0)*val1*val2)+val3)!=val5)!=1))+(float)((((((val9[2]-val0)*val1*val2)+val3)!=val5)!=1))+(float)((((((val7[1]-val0)*val1*val2)+val3)!=val5)!=1))+(float)((((((val9[3]-val0)*val1*val2)+val3)!=val5)!=1)));
        float4 val10 = *((float4*)(data1+alu3));
        *(data0+alu1) = ((float)((((((val10[2]-val0)*val1*val2)+val3)!=val4)!=1))+(float)((((((val9[0]-val0)*val1*val2)+val3)!=val4)!=1))+(float)((((((val10[3]-val0)*val1*val2)+val3)!=val4)!=1))+(float)((((((val9[1]-val0)*val1*val2)+val3)!=val4)!=1)));
        *(data0+alu0) = ((float)((((((val10[0]-val0)*val1*val2)+val3)!=val6)!=1))+(float)((((((val8[0]-val0)*val1*val2)+val3)!=val6)!=1))+(float)((((((val10[1]-val0)*val1*val2)+val3)!=val6)!=1))+(float)((((((val8[1]-val0)*val1*val2)+val3)!=val6)!=1)));
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_128_10_144_4_4(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3) {
  for (int ridx0 = 0; ridx0 < 128; ridx0++) {
    for (int ridx1 = 0; ridx1 < 10; ridx1++) {
      int alu0 = ((ridx0*40)+ridx1);
      float acc0 = 0.0f;
      float acc1 = 0.0f;
      float acc2 = 0.0f;
      float acc3 = 0.0f;
      for (int ridx2 = 0; ridx2 < 144; ridx2++) {
        int alu1 = (ridx2<<2);
        int alu2 = ((ridx0*2304)+alu1);
        float4 val0 = *((float4*)(data1+alu2+576));
        float4 val1 = *((float4*)(data1+alu2+1152));
        float4 val2 = *((float4*)(data1+alu2+1728));
        float4 val3 = *((float4*)(data1+alu2));
        float4 val4 = *((float4*)(data2+(ridx1*576)+alu1));
        acc0 = (acc0+(val3[0]*val4[0])+(val3[1]*val4[1])+(val3[2]*val4[2])+(val3[3]*val4[3]));
        acc1 = (acc1+(val0[0]*val4[0])+(val0[1]*val4[1])+(val0[2]*val4[2])+(val0[3]*val4[3]));
        acc2 = (acc2+(val1[0]*val4[0])+(val1[1]*val4[1])+(val1[2]*val4[2])+(val1[3]*val4[3]));
        acc3 = (acc3+(val2[0]*val4[0])+(val2[1]*val4[1])+(val2[2]*val4[2])+(val2[3]*val4[3]));
      }
      float val5 = *(data3+ridx1);
      *(data0+alu0+10) = (acc1+val5);
      *(data0+alu0+20) = (acc2+val5);
      *(data0+alu0+30) = (acc3+val5);
      *(data0+alu0) = (acc0+val5);
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
void r_512_10(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    int alu0 = (ridx0*10);
    float2 val0 = *((float2*)(data1+alu0+2));
    float2 val1 = *((float2*)(data1+alu0+4));
    float2 val2 = *((float2*)(data1+alu0+6));
    float2 val3 = *((float2*)(data1+alu0+8));
    float2 val4 = *((float2*)(data1+alu0));
    float alu1 = ((val4[0]<val4[1])?val4[1]:val4[0]);
    float alu2 = ((alu1<val0[0])?val0[0]:alu1);
    float alu3 = ((alu2<val0[1])?val0[1]:alu2);
    float alu4 = ((alu3<val1[0])?val1[0]:alu3);
    float alu5 = ((alu4<val1[1])?val1[1]:alu4);
    float alu6 = ((alu5<val2[0])?val2[0]:alu5);
    float alu7 = ((alu6<val2[1])?val2[1]:alu6);
    float alu8 = ((alu7<val3[0])?val3[0]:alu7);
    *(data0+ridx0) = ((alu8<val3[1])?val3[1]:alu8);
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
void r_512_10n1(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    int alu0 = (ridx0*10);
    float val0 = *(data2+ridx0);
    float2 val1 = *((float2*)(data1+alu0+2));
    float alu1 = ((val1[0]-val0)*1.4426950408889634f);
    _Bool alu2 = (alu1!=-__builtin_inff());
    _Bool alu3 = (alu1!=__builtin_inff());
    _Bool alu4 = (alu1!=alu1);
    float alu5 = ((val1[1]-val0)*1.4426950408889634f);
    _Bool alu6 = (alu5!=-__builtin_inff());
    _Bool alu7 = (alu5!=__builtin_inff());
    _Bool alu8 = (alu5!=alu5);
    float alu9 = (alu3?(alu4?0.0f:(alu2?alu1:0.0f)):0.0f);
    int cast0 = (int)((alu9+((alu9<0.0f)?-0.5f:0.5f)));
    int alu10 = (cast0>>1);
    int precast0 = ((alu10<<23)+1065353216);
    int precast1 = (((cast0-alu10)<<23)+1065353216);
    float alu11 = (alu9-(float)(cast0));
    float alu12 = (alu7?(alu8?0.0f:(alu6?alu5:0.0f)):0.0f);
    int cast1 = (int)((alu12+((alu12<0.0f)?-0.5f:0.5f)));
    int alu13 = (cast1>>1);
    int precast2 = ((alu13<<23)+1065353216);
    int precast3 = (((cast1-alu13)<<23)+1065353216);
    float alu14 = (alu12-(float)(cast1));
    float2 val2 = *((float2*)(data1+alu0+4));
    float alu15 = ((val2[0]-val0)*1.4426950408889634f);
    _Bool alu16 = (alu15!=-__builtin_inff());
    _Bool alu17 = (alu15!=__builtin_inff());
    _Bool alu18 = (alu15!=alu15);
    float alu19 = ((val2[1]-val0)*1.4426950408889634f);
    _Bool alu20 = (alu19!=-__builtin_inff());
    _Bool alu21 = (alu19!=__builtin_inff());
    _Bool alu22 = (alu19!=alu19);
    float alu23 = (alu17?(alu18?0.0f:(alu16?alu15:0.0f)):0.0f);
    int cast2 = (int)((alu23+((alu23<0.0f)?-0.5f:0.5f)));
    int alu24 = (cast2>>1);
    int precast4 = ((alu24<<23)+1065353216);
    int precast5 = (((cast2-alu24)<<23)+1065353216);
    float alu25 = (alu23-(float)(cast2));
    float alu26 = (alu21?(alu22?0.0f:(alu20?alu19:0.0f)):0.0f);
    int cast3 = (int)((alu26+((alu26<0.0f)?-0.5f:0.5f)));
    int alu27 = (cast3>>1);
    int precast6 = ((alu27<<23)+1065353216);
    int precast7 = (((cast3-alu27)<<23)+1065353216);
    float alu28 = (alu26-(float)(cast3));
    float2 val3 = *((float2*)(data1+alu0+6));
    float alu29 = ((val3[0]-val0)*1.4426950408889634f);
    _Bool alu30 = (alu29!=-__builtin_inff());
    _Bool alu31 = (alu29!=__builtin_inff());
    _Bool alu32 = (alu29!=alu29);
    float alu33 = ((val3[1]-val0)*1.4426950408889634f);
    _Bool alu34 = (alu33!=-__builtin_inff());
    _Bool alu35 = (alu33!=__builtin_inff());
    _Bool alu36 = (alu33!=alu33);
    float alu37 = (alu31?(alu32?0.0f:(alu30?alu29:0.0f)):0.0f);
    int cast4 = (int)((alu37+((alu37<0.0f)?-0.5f:0.5f)));
    int alu38 = (cast4>>1);
    int precast8 = ((alu38<<23)+1065353216);
    int precast9 = (((cast4-alu38)<<23)+1065353216);
    float alu39 = (alu37-(float)(cast4));
    float alu40 = (alu35?(alu36?0.0f:(alu34?alu33:0.0f)):0.0f);
    int cast5 = (int)((alu40+((alu40<0.0f)?-0.5f:0.5f)));
    int alu41 = (cast5>>1);
    int precast10 = ((alu41<<23)+1065353216);
    int precast11 = (((cast5-alu41)<<23)+1065353216);
    float alu42 = (alu40-(float)(cast5));
    float2 val4 = *((float2*)(data1+alu0+8));
    float alu43 = ((val4[0]-val0)*1.4426950408889634f);
    _Bool alu44 = (alu43!=-__builtin_inff());
    _Bool alu45 = (alu43!=__builtin_inff());
    _Bool alu46 = (alu43!=alu43);
    float alu47 = ((val4[1]-val0)*1.4426950408889634f);
    _Bool alu48 = (alu47!=-__builtin_inff());
    _Bool alu49 = (alu47!=__builtin_inff());
    _Bool alu50 = (alu47!=alu47);
    float alu51 = (alu45?(alu46?0.0f:(alu44?alu43:0.0f)):0.0f);
    int cast6 = (int)((alu51+((alu51<0.0f)?-0.5f:0.5f)));
    int alu52 = (cast6>>1);
    int precast12 = ((alu52<<23)+1065353216);
    int precast13 = (((cast6-alu52)<<23)+1065353216);
    float alu53 = (alu51-(float)(cast6));
    float alu54 = (alu49?(alu50?0.0f:(alu48?alu47:0.0f)):0.0f);
    int cast7 = (int)((alu54+((alu54<0.0f)?-0.5f:0.5f)));
    int alu55 = (cast7>>1);
    int precast14 = ((alu55<<23)+1065353216);
    int precast15 = (((cast7-alu55)<<23)+1065353216);
    float alu56 = (alu54-(float)(cast7));
    float2 val5 = *((float2*)(data1+alu0));
    float alu57 = ((val5[0]-val0)*1.4426950408889634f);
    _Bool alu58 = (alu57!=-__builtin_inff());
    _Bool alu59 = (alu57!=__builtin_inff());
    _Bool alu60 = (alu57!=alu57);
    float alu61 = ((val5[1]-val0)*1.4426950408889634f);
    _Bool alu62 = (alu61!=-__builtin_inff());
    _Bool alu63 = (alu61!=__builtin_inff());
    _Bool alu64 = (alu61!=alu61);
    float alu65 = (alu59?(alu60?0.0f:(alu58?alu57:0.0f)):0.0f);
    int cast8 = (int)((alu65+((alu65<0.0f)?-0.5f:0.5f)));
    int alu66 = (cast8>>1);
    int precast16 = ((alu66<<23)+1065353216);
    int precast17 = (((cast8-alu66)<<23)+1065353216);
    float alu67 = (alu65-(float)(cast8));
    float alu68 = (alu63?(alu64?0.0f:(alu62?alu61:0.0f)):0.0f);
    int cast9 = (int)((alu68+((alu68<0.0f)?-0.5f:0.5f)));
    int alu69 = (cast9>>1);
    int precast18 = ((alu69<<23)+1065353216);
    int precast19 = (((cast9-alu69)<<23)+1065353216);
    float alu70 = (alu68-(float)(cast9));
    *(data0+ridx0) = ((alu59?(alu60?__builtin_nanf(""):(alu58?((alu65<__builtin_inff())?((alu65<-150.0f)?0.0f:((alu65<128.0f)?((alu65!=128.0f)?(((((((((((((alu67*0.0001535920892f)+0.001339262701f)*alu67)+0.009618384764f)*alu67)+0.05550347269f)*alu67)+0.2402264476f)*alu67)+0.6931471825f)*alu67)+1.0f)*(*((float*)&precast16))*(*((float*)&precast17))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu63?(alu64?__builtin_nanf(""):(alu62?((alu68<__builtin_inff())?((alu68<-150.0f)?0.0f:((alu68<128.0f)?((alu68!=128.0f)?(((((((((((((alu70*0.0001535920892f)+0.001339262701f)*alu70)+0.009618384764f)*alu70)+0.05550347269f)*alu70)+0.2402264476f)*alu70)+0.6931471825f)*alu70)+1.0f)*(*((float*)&precast18))*(*((float*)&precast19))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu3?(alu4?__builtin_nanf(""):(alu2?((alu9<__builtin_inff())?((alu9<-150.0f)?0.0f:((alu9<128.0f)?((alu9!=128.0f)?(((((((((((((alu11*0.0001535920892f)+0.001339262701f)*alu11)+0.009618384764f)*alu11)+0.05550347269f)*alu11)+0.2402264476f)*alu11)+0.6931471825f)*alu11)+1.0f)*(*((float*)&precast0))*(*((float*)&precast1))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu7?(alu8?__builtin_nanf(""):(alu6?((alu12<__builtin_inff())?((alu12<-150.0f)?0.0f:((alu12<128.0f)?((alu12!=128.0f)?(((((((((((((alu14*0.0001535920892f)+0.001339262701f)*alu14)+0.009618384764f)*alu14)+0.05550347269f)*alu14)+0.2402264476f)*alu14)+0.6931471825f)*alu14)+1.0f)*(*((float*)&precast2))*(*((float*)&precast3))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu17?(alu18?__builtin_nanf(""):(alu16?((alu23<__builtin_inff())?((alu23<-150.0f)?0.0f:((alu23<128.0f)?((alu23!=128.0f)?(((((((((((((alu25*0.0001535920892f)+0.001339262701f)*alu25)+0.009618384764f)*alu25)+0.05550347269f)*alu25)+0.2402264476f)*alu25)+0.6931471825f)*alu25)+1.0f)*(*((float*)&precast4))*(*((float*)&precast5))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu21?(alu22?__builtin_nanf(""):(alu20?((alu26<__builtin_inff())?((alu26<-150.0f)?0.0f:((alu26<128.0f)?((alu26!=128.0f)?(((((((((((((alu28*0.0001535920892f)+0.001339262701f)*alu28)+0.009618384764f)*alu28)+0.05550347269f)*alu28)+0.2402264476f)*alu28)+0.6931471825f)*alu28)+1.0f)*(*((float*)&precast6))*(*((float*)&precast7))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu31?(alu32?__builtin_nanf(""):(alu30?((alu37<__builtin_inff())?((alu37<-150.0f)?0.0f:((alu37<128.0f)?((alu37!=128.0f)?(((((((((((((alu39*0.0001535920892f)+0.001339262701f)*alu39)+0.009618384764f)*alu39)+0.05550347269f)*alu39)+0.2402264476f)*alu39)+0.6931471825f)*alu39)+1.0f)*(*((float*)&precast8))*(*((float*)&precast9))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu35?(alu36?__builtin_nanf(""):(alu34?((alu40<__builtin_inff())?((alu40<-150.0f)?0.0f:((alu40<128.0f)?((alu40!=128.0f)?(((((((((((((alu42*0.0001535920892f)+0.001339262701f)*alu42)+0.009618384764f)*alu42)+0.05550347269f)*alu42)+0.2402264476f)*alu42)+0.6931471825f)*alu42)+1.0f)*(*((float*)&precast10))*(*((float*)&precast11))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu45?(alu46?__builtin_nanf(""):(alu44?((alu51<__builtin_inff())?((alu51<-150.0f)?0.0f:((alu51<128.0f)?((alu51!=128.0f)?(((((((((((((alu53*0.0001535920892f)+0.001339262701f)*alu53)+0.009618384764f)*alu53)+0.05550347269f)*alu53)+0.2402264476f)*alu53)+0.6931471825f)*alu53)+1.0f)*(*((float*)&precast12))*(*((float*)&precast13))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())+(alu49?(alu50?__builtin_nanf(""):(alu48?((alu54<__builtin_inff())?((alu54<-150.0f)?0.0f:((alu54<128.0f)?((alu54!=128.0f)?(((((((((((((alu56*0.0001535920892f)+0.001339262701f)*alu56)+0.009618384764f)*alu56)+0.05550347269f)*alu56)+0.2402264476f)*alu56)+0.6931471825f)*alu56)+1.0f)*(*((float*)&precast14))*(*((float*)&precast15))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff()));
  }
}

void r_512_10n2(float* restrict data0, int* restrict data1, int* restrict data2, float* restrict data3) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    int val0 = *(data1+0);
    int val1 = *(data1+1);
    int val2 = *(data1+2);
    int val3 = *(data1+3);
    int val4 = *(data1+4);
    int val5 = *(data1+5);
    int val6 = *(data1+6);
    int val7 = *(data1+7);
    int val8 = *(data1+8);
    int val9 = *(data1+9);
    int val10 = *(data2+ridx0);
    float val11 = *(data3+ridx0);
    *(data0+ridx0) = ((((float)(((val0!=val10)!=1))*0.001953125f)+((float)(((val1!=val10)!=1))*0.001953125f)+((float)(((val2!=val10)!=1))*0.001953125f)+((float)(((val3!=val10)!=1))*0.001953125f)+((float)(((val4!=val10)!=1))*0.001953125f)+((float)(((val5!=val10)!=1))*0.001953125f)+((float)(((val6!=val10)!=1))*0.001953125f)+((float)(((val7!=val10)!=1))*0.001953125f)+((float)(((val8!=val10)!=1))*0.001953125f)+((float)(((val9!=val10)!=1))*0.001953125f))*(1/val11));
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_128_10_4(float* restrict data0, int* restrict data1, int* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5) {
  for (int ridx0 = 0; ridx0 < 128; ridx0++) {
    int alu0 = (ridx0<<2);
    for (int ridx1 = 0; ridx1 < 10; ridx1++) {
      int alu1 = ((ridx0*40)+ridx1);
      int alu2 = (alu1+10);
      int alu3 = (alu1+20);
      int alu4 = (alu1+30);
      int val0 = *(data1+ridx1);
      int val1 = *(data2+alu0+1);
      int val2 = *(data2+alu0+2);
      int val3 = *(data2+alu0+3);
      int val4 = *(data2+alu0);
      float val5 = *(data3+alu2);
      float val6 = *(data3+alu3);
      float val7 = *(data3+alu4);
      float val8 = *(data3+alu1);
      float4 val9 = *((float4*)(data4+alu0));
      float alu5 = ((val5-val9[1])*1.4426950408889634f);
      _Bool alu6 = (alu5!=-__builtin_inff());
      _Bool alu7 = (alu5!=__builtin_inff());
      _Bool alu8 = (alu5!=alu5);
      float alu9 = ((val6-val9[2])*1.4426950408889634f);
      _Bool alu10 = (alu9!=-__builtin_inff());
      _Bool alu11 = (alu9!=__builtin_inff());
      _Bool alu12 = (alu9!=alu9);
      float alu13 = ((val7-val9[3])*1.4426950408889634f);
      _Bool alu14 = (alu13!=-__builtin_inff());
      _Bool alu15 = (alu13!=__builtin_inff());
      _Bool alu16 = (alu13!=alu13);
      float alu17 = ((val8-val9[0])*1.4426950408889634f);
      _Bool alu18 = (alu17!=-__builtin_inff());
      _Bool alu19 = (alu17!=__builtin_inff());
      _Bool alu20 = (alu17!=alu17);
      float alu21 = (alu7?(alu8?0.0f:(alu6?alu5:0.0f)):0.0f);
      int cast0 = (int)((alu21+((alu21<0.0f)?-0.5f:0.5f)));
      int alu22 = (cast0>>1);
      int precast0 = ((alu22<<23)+1065353216);
      int precast1 = (((cast0-alu22)<<23)+1065353216);
      float alu23 = (alu21-(float)(cast0));
      float alu24 = (alu11?(alu12?0.0f:(alu10?alu9:0.0f)):0.0f);
      int cast1 = (int)((alu24+((alu24<0.0f)?-0.5f:0.5f)));
      int alu25 = (cast1>>1);
      int precast2 = ((alu25<<23)+1065353216);
      int precast3 = (((cast1-alu25)<<23)+1065353216);
      float alu26 = (alu24-(float)(cast1));
      float alu27 = (alu15?(alu16?0.0f:(alu14?alu13:0.0f)):0.0f);
      int cast2 = (int)((alu27+((alu27<0.0f)?-0.5f:0.5f)));
      int alu28 = (cast2>>1);
      int precast4 = ((alu28<<23)+1065353216);
      int precast5 = (((cast2-alu28)<<23)+1065353216);
      float alu29 = (alu27-(float)(cast2));
      float alu30 = (alu19?(alu20?0.0f:(alu18?alu17:0.0f)):0.0f);
      int cast3 = (int)((alu30+((alu30<0.0f)?-0.5f:0.5f)));
      int alu31 = (cast3>>1);
      int precast6 = ((alu31<<23)+1065353216);
      int precast7 = (((cast3-alu31)<<23)+1065353216);
      float alu32 = (alu30-(float)(cast3));
      float4 val10 = *((float4*)(data5+alu0));
      *(data0+alu2) = (((float)(((val0!=val1)!=1))*-0.001953125f)+((alu7?(alu8?__builtin_nanf(""):(alu6?((alu21<__builtin_inff())?((alu21<-150.0f)?0.0f:((alu21<128.0f)?((alu21!=128.0f)?(((((((((((((alu23*0.0001535920892f)+0.001339262701f)*alu23)+0.009618384764f)*alu23)+0.05550347269f)*alu23)+0.2402264476f)*alu23)+0.6931471825f)*alu23)+1.0f)*(*((float*)&precast0))*(*((float*)&precast1))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())*val10[1]));
      *(data0+alu3) = (((float)(((val0!=val2)!=1))*-0.001953125f)+((alu11?(alu12?__builtin_nanf(""):(alu10?((alu24<__builtin_inff())?((alu24<-150.0f)?0.0f:((alu24<128.0f)?((alu24!=128.0f)?(((((((((((((alu26*0.0001535920892f)+0.001339262701f)*alu26)+0.009618384764f)*alu26)+0.05550347269f)*alu26)+0.2402264476f)*alu26)+0.6931471825f)*alu26)+1.0f)*(*((float*)&precast2))*(*((float*)&precast3))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())*val10[2]));
      *(data0+alu4) = (((float)(((val0!=val3)!=1))*-0.001953125f)+((alu15?(alu16?__builtin_nanf(""):(alu14?((alu27<__builtin_inff())?((alu27<-150.0f)?0.0f:((alu27<128.0f)?((alu27!=128.0f)?(((((((((((((alu29*0.0001535920892f)+0.001339262701f)*alu29)+0.009618384764f)*alu29)+0.05550347269f)*alu29)+0.2402264476f)*alu29)+0.6931471825f)*alu29)+1.0f)*(*((float*)&precast4))*(*((float*)&precast5))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())*val10[3]));
      *(data0+alu1) = (((float)(((val0!=val4)!=1))*-0.001953125f)+((alu19?(alu20?__builtin_nanf(""):(alu18?((alu30<__builtin_inff())?((alu30<-150.0f)?0.0f:((alu30<128.0f)?((alu30!=128.0f)?(((((((((((((alu32*0.0001535920892f)+0.001339262701f)*alu32)+0.009618384764f)*alu32)+0.05550347269f)*alu32)+0.2402264476f)*alu32)+0.6931471825f)*alu32)+1.0f)*(*((float*)&precast6))*(*((float*)&precast7))):__builtin_inff()):__builtin_inff())):__builtin_nanf("")):0.0f)):__builtin_inff())*val10[0]));
    }
  }
}

void r3_10_128_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 10; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 128; ridx1++) {
      int alu0 = (ridx0+(ridx1*40));
      float val0 = *(data1+alu0+10);
      float val1 = *(data1+alu0+20);
      float val2 = *(data1+alu0+30);
      float val3 = *(data1+alu0);
      acc0 = (acc0+val3+val0+val1+val2);
    }
    float val4 = *(data0+ridx0);
    float alu1 = ((val4*0.9f)+(acc0*0.09999999999999998f));
    *(data0+ridx0) = alu1;
    float val5 = *(data2+ridx0);
    float alu2 = ((val5*0.999f)+(acc0*acc0*0.0010000000000000009f));
    *(data2+ridx0) = alu2;
    float val6 = *(data3+ridx0);
    float val7 = *(data4+0);
    float val8 = *(data5+0);
    float val9 = *(data6+0);
    *(data3+ridx0) = (val6-(val7*alu1*(1/(val8*(__builtin_sqrtf((alu2*(1/val9)))+1e-08f)))));
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_128_192_4_3_10(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 128; ridx0++) {
    int alu0 = (ridx0*40);
    for (int ridx1 = 0; ridx1 < 192; ridx1++) {
      int alu1 = (ridx1*3);
      int alu2 = ((ridx0*2304)+alu1);
      float val0 = *(data1+alu1+1);
      float val1 = *(data1+alu1+2);
      float val2 = *(data1+alu1+576);
      float val3 = *(data1+alu1+577);
      float val4 = *(data1+alu1+578);
      float val5 = *(data1+alu1+1152);
      float val6 = *(data1+alu1+1153);
      float val7 = *(data1+alu1+1154);
      float val8 = *(data1+alu1+1728);
      float val9 = *(data1+alu1+1729);
      float val10 = *(data1+alu1+1730);
      float val11 = *(data1+alu1+2304);
      float val12 = *(data1+alu1+2305);
      float val13 = *(data1+alu1+2306);
      float val14 = *(data1+alu1+2880);
      float val15 = *(data1+alu1+2881);
      float val16 = *(data1+alu1+2882);
      float val17 = *(data1+alu1+3456);
      float val18 = *(data1+alu1+3457);
      float val19 = *(data1+alu1+3458);
      float val20 = *(data1+alu1+4032);
      float val21 = *(data1+alu1+4033);
      float val22 = *(data1+alu1+4034);
      float val23 = *(data1+alu1+4608);
      float val24 = *(data1+alu1+4609);
      float val25 = *(data1+alu1+4610);
      float val26 = *(data1+alu1+5184);
      float val27 = *(data1+alu1+5185);
      float val28 = *(data1+alu1+5186);
      float val29 = *(data1+alu1);
      float4 val30 = *((float4*)(data2+alu0+4));
      float4 val31 = *((float4*)(data2+alu0+8));
      float4 val32 = *((float4*)(data2+alu0+12));
      float4 val33 = *((float4*)(data2+alu0+16));
      *(data0+alu2+576) = ((val29*val31[2])+(val2*val31[3])+(val5*val32[0])+(val8*val32[1])+(val11*val32[2])+(val14*val32[3])+(val17*val33[0])+(val20*val33[1])+(val23*val33[2])+(val26*val33[3]));
      *(data0+alu2+577) = ((val0*val31[2])+(val3*val31[3])+(val6*val32[0])+(val9*val32[1])+(val12*val32[2])+(val15*val32[3])+(val18*val33[0])+(val21*val33[1])+(val24*val33[2])+(val27*val33[3]));
      *(data0+alu2+578) = ((val1*val31[2])+(val4*val31[3])+(val7*val32[0])+(val10*val32[1])+(val13*val32[2])+(val16*val32[3])+(val19*val33[0])+(val22*val33[1])+(val25*val33[2])+(val28*val33[3]));
      float4 val34 = *((float4*)(data2+alu0+20));
      float4 val35 = *((float4*)(data2+alu0+24));
      float4 val36 = *((float4*)(data2+alu0+28));
      *(data0+alu2+1152) = ((val29*val34[0])+(val2*val34[1])+(val5*val34[2])+(val8*val34[3])+(val11*val35[0])+(val14*val35[1])+(val17*val35[2])+(val20*val35[3])+(val23*val36[0])+(val26*val36[1]));
      *(data0+alu2+1153) = ((val0*val34[0])+(val3*val34[1])+(val6*val34[2])+(val9*val34[3])+(val12*val35[0])+(val15*val35[1])+(val18*val35[2])+(val21*val35[3])+(val24*val36[0])+(val27*val36[1]));
      *(data0+alu2+1154) = ((val1*val34[0])+(val4*val34[1])+(val7*val34[2])+(val10*val34[3])+(val13*val35[0])+(val16*val35[1])+(val19*val35[2])+(val22*val35[3])+(val25*val36[0])+(val28*val36[1]));
      float4 val37 = *((float4*)(data2+alu0+32));
      float4 val38 = *((float4*)(data2+alu0+36));
      *(data0+alu2+1728) = ((val29*val36[2])+(val2*val36[3])+(val5*val37[0])+(val8*val37[1])+(val11*val37[2])+(val14*val37[3])+(val17*val38[0])+(val20*val38[1])+(val23*val38[2])+(val26*val38[3]));
      *(data0+alu2+1729) = ((val0*val36[2])+(val3*val36[3])+(val6*val37[0])+(val9*val37[1])+(val12*val37[2])+(val15*val37[3])+(val18*val38[0])+(val21*val38[1])+(val24*val38[2])+(val27*val38[3]));
      *(data0+alu2+1730) = ((val1*val36[2])+(val4*val36[3])+(val7*val37[0])+(val10*val37[1])+(val13*val37[2])+(val16*val37[3])+(val19*val38[0])+(val22*val38[1])+(val25*val38[2])+(val28*val38[3]));
      float4 val39 = *((float4*)(data2+alu0));
      *(data0+alu2+1) = ((val0*val39[0])+(val3*val39[1])+(val6*val39[2])+(val9*val39[3])+(val12*val30[0])+(val15*val30[1])+(val18*val30[2])+(val21*val30[3])+(val24*val31[0])+(val27*val31[1]));
      *(data0+alu2+2) = ((val1*val39[0])+(val4*val39[1])+(val7*val39[2])+(val10*val39[3])+(val13*val30[0])+(val16*val30[1])+(val19*val30[2])+(val22*val30[3])+(val25*val31[0])+(val28*val31[1]));
      *(data0+alu2) = ((val29*val39[0])+(val2*val39[1])+(val5*val39[2])+(val8*val39[3])+(val11*val30[0])+(val14*val30[1])+(val17*val30[2])+(val20*val30[3])+(val23*val31[0])+(val26*val31[1]));
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
void r_64_512_6_6n2(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8, float* restrict data9) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    float val0 = *(data2+ridx0);
    float val1 = *(data3+ridx0);
    float val2 = *(data5+ridx0);
    float val3 = *(data4+ridx0);
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 512; ridx1++) {
      for (int ridx2 = 0; ridx2 < 6; ridx2++) {
        int alu0 = ((ridx0*36)+(ridx1*2304)+(ridx2*6));
        int alu1 = (((ridx2>>1)*3)+(ridx0*9)+(ridx1*576));
        int alu2 = (alu1+1);
        int alu3 = (alu1+2);
        float val4 = *(data6+alu2);
        float val5 = *(data6+alu3);
        float val6 = *(data6+alu1);
        float val7 = *(data7+alu2);
        float alu4 = (1/val7);
        float val8 = *(data7+alu3);
        float alu5 = (1/val8);
        float val9 = *(data7+alu1);
        float alu6 = (1/val9);
        float val10 = *(data8+alu2);
        float val11 = *(data8+alu3);
        float val12 = *(data8+alu1);
        float2 val13 = *((float2*)(data1+alu0+2));
        float alu7 = ((val13[0]-val0)*val1);
        float alu8 = ((val13[1]-val0)*val1);
        float2 val14 = *((float2*)(data1+alu0+4));
        float alu9 = ((val14[0]-val0)*val1);
        float alu10 = ((val14[1]-val0)*val1);
        float2 val15 = *((float2*)(data1+alu0));
        float alu11 = ((val15[0]-val0)*val1);
        float alu12 = ((val15[1]-val0)*val1);
        acc0 = (acc0+(alu11*(float)(((((alu11*val3)+val2)!=val6)!=1))*alu6*val12)+(alu12*(float)(((((alu12*val3)+val2)!=val6)!=1))*alu6*val12)+(alu7*(float)(((((alu7*val3)+val2)!=val4)!=1))*alu4*val10)+(alu8*(float)(((((alu8*val3)+val2)!=val4)!=1))*alu4*val10)+(alu9*(float)(((((alu9*val3)+val2)!=val5)!=1))*alu5*val11)+(alu10*(float)(((((alu10*val3)+val2)!=val5)!=1))*alu5*val11));
      }
    }
    float val16 = *(data9+ridx0);
    float alu13 = ((val16*5.425347262644209e-05f)+1e-05f);
    *(data0+ridx0) = (acc0*(1/(val3*alu13*alu13*2.0f))*-5.425347262644209e-05f);
  }
}

void r3_10_192_128_3_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7) {
  for (int ridx0 = 0; ridx0 < 10; ridx0++) {
    for (int ridx1 = 0; ridx1 < 192; ridx1++) {
      int alu0 = (ridx1*3);
      int alu1 = ((ridx0*576)+alu0);
      int alu2 = (alu1+1);
      int alu3 = (alu1+2);
      float acc0 = 0.0f;
      float acc1 = 0.0f;
      float acc2 = 0.0f;
      for (int ridx2 = 0; ridx2 < 128; ridx2++) {
        int alu4 = (alu0+(ridx2*2304));
        int alu5 = (ridx0+(ridx2*40));
        float val0 = *(data1+alu4+1);
        float val1 = *(data1+alu4+2);
        float val2 = *(data1+alu4+576);
        float val3 = *(data1+alu4+577);
        float val4 = *(data1+alu4+578);
        float val5 = *(data1+alu4+1152);
        float val6 = *(data1+alu4+1153);
        float val7 = *(data1+alu4+1154);
        float val8 = *(data1+alu4+1728);
        float val9 = *(data1+alu4+1729);
        float val10 = *(data1+alu4+1730);
        float val11 = *(data1+alu4);
        float val12 = *(data2+alu5+10);
        float val13 = *(data2+alu5+20);
        float val14 = *(data2+alu5+30);
        float val15 = *(data2+alu5);
        acc0 = (acc0+(val11*val15)+(val2*val12)+(val5*val13)+(val8*val14));
        acc1 = (acc1+(val0*val15)+(val3*val12)+(val6*val13)+(val9*val14));
        acc2 = (acc2+(val1*val15)+(val4*val12)+(val7*val13)+(val10*val14));
      }
      float val16 = *(data0+alu2);
      float alu6 = ((val16*0.9f)+(acc1*0.09999999999999998f));
      *(data0+alu2) = alu6;
      float val17 = *(data0+alu3);
      float alu7 = ((val17*0.9f)+(acc2*0.09999999999999998f));
      *(data0+alu3) = alu7;
      float val18 = *(data0+alu1);
      float alu8 = ((val18*0.9f)+(acc0*0.09999999999999998f));
      *(data0+alu1) = alu8;
      float val19 = *(data3+alu2);
      float alu9 = ((val19*0.999f)+(acc1*acc1*0.0010000000000000009f));
      *(data3+alu2) = alu9;
      float val20 = *(data3+alu3);
      float alu10 = ((val20*0.999f)+(acc2*acc2*0.0010000000000000009f));
      *(data3+alu3) = alu10;
      float val21 = *(data3+alu1);
      float alu11 = ((val21*0.999f)+(acc0*acc0*0.0010000000000000009f));
      *(data3+alu1) = alu11;
      float val22 = *(data4+alu2);
      float val23 = *(data4+alu3);
      float val24 = *(data4+alu1);
      float val25 = *(data5+0);
      float val26 = *(data6+0);
      float val27 = *(data7+0);
      float alu12 = (1/val27);
      *(data4+alu2) = (val22-(val25*alu6*(1/(val26*(__builtin_sqrtf((alu9*alu12))+1e-08f)))));
      *(data4+alu3) = (val23-(val25*alu7*(1/(val26*(__builtin_sqrtf((alu10*alu12))+1e-08f)))));
      *(data4+alu1) = (val24-(val25*alu8*(1/(val26*(__builtin_sqrtf((alu11*alu12))+1e-08f)))));
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
void r_64_512_6_6n3(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    float val0 = *(data1+ridx0);
    float val1 = *(data2+ridx0);
    float val2 = *(data4+ridx0);
    float val3 = *(data5+ridx0);
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 512; ridx1++) {
      for (int ridx2 = 0; ridx2 < 6; ridx2++) {
        int alu0 = ((ridx0*36)+(ridx1*2304)+(ridx2*6));
        int alu1 = (((ridx2>>1)*3)+(ridx0*9)+(ridx1*576));
        int alu2 = (alu1+1);
        int alu3 = (alu1+2);
        float val4 = *(data6+alu2);
        float val5 = *(data6+alu3);
        float val6 = *(data6+alu1);
        float val7 = *(data7+alu2);
        float alu4 = (1/val7);
        float val8 = *(data7+alu3);
        float alu5 = (1/val8);
        float val9 = *(data7+alu1);
        float alu6 = (1/val9);
        float val10 = *(data8+alu2);
        float val11 = *(data8+alu3);
        float val12 = *(data8+alu1);
        float2 val13 = *((float2*)(data3+alu0+2));
        float2 val14 = *((float2*)(data3+alu0+4));
        float2 val15 = *((float2*)(data3+alu0));
        acc0 = (acc0+(((((-(val0*val1*(float)((((((val15[0]-val2)*val0*val1)+val3)!=val6)!=1))*alu6*val12)-(val0*val1*(float)((((((val15[1]-val2)*val0*val1)+val3)!=val6)!=1))*alu6*val12))-(val0*val1*(float)((((((val13[0]-val2)*val0*val1)+val3)!=val4)!=1))*alu4*val10))-(val0*val1*(float)((((((val13[1]-val2)*val0*val1)+val3)!=val4)!=1))*alu4*val10))-(val0*val1*(float)((((((val14[0]-val2)*val0*val1)+val3)!=val5)!=1))*alu5*val11))-(val0*val1*(float)((((((val14[1]-val2)*val0*val1)+val3)!=val5)!=1))*alu5*val11)));
      }
    }
    *(data0+ridx0) = (acc0*5.425347262644209e-05f);
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
void r_64_512_6_6n4(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    float val0 = *(data2+ridx0);
    float val1 = *(data3+ridx0);
    float val2 = *(data4+ridx0);
    float val3 = *(data5+ridx0);
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 512; ridx1++) {
      for (int ridx2 = 0; ridx2 < 6; ridx2++) {
        int alu0 = ((ridx0*36)+(ridx1*2304)+(ridx2*6));
        int alu1 = (((ridx2>>1)*3)+(ridx0*9)+(ridx1*576));
        int alu2 = (alu1+1);
        int alu3 = (alu1+2);
        float val4 = *(data6+alu2);
        float val5 = *(data6+alu3);
        float val6 = *(data6+alu1);
        float val7 = *(data7+alu2);
        float alu4 = (1/val7);
        float val8 = *(data7+alu3);
        float alu5 = (1/val8);
        float val9 = *(data7+alu1);
        float alu6 = (1/val9);
        float val10 = *(data8+alu2);
        float val11 = *(data8+alu3);
        float val12 = *(data8+alu1);
        float2 val13 = *((float2*)(data1+alu0+2));
        float alu7 = (val13[0]-val0);
        float alu8 = (val13[1]-val0);
        float2 val14 = *((float2*)(data1+alu0+4));
        float alu9 = (val14[0]-val0);
        float alu10 = (val14[1]-val0);
        float2 val15 = *((float2*)(data1+alu0));
        float alu11 = (val15[0]-val0);
        float alu12 = (val15[1]-val0);
        acc0 = (acc0+(alu11*val1*(float)(((((alu11*val2*val1)+val3)!=val6)!=1))*alu6*val12)+(alu12*val1*(float)(((((alu12*val2*val1)+val3)!=val6)!=1))*alu6*val12)+(alu7*val1*(float)(((((alu7*val2*val1)+val3)!=val4)!=1))*alu4*val10)+(alu8*val1*(float)(((((alu8*val2*val1)+val3)!=val4)!=1))*alu4*val10)+(alu9*val1*(float)(((((alu9*val2*val1)+val3)!=val5)!=1))*alu5*val11)+(alu10*val1*(float)(((((alu10*val2*val1)+val3)!=val5)!=1))*alu5*val11));
      }
    }
    *(data0+ridx0) = acc0;
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
void r_64_512_6_6n5(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    float val0 = *(data2+ridx0);
    float val1 = *(data3+ridx0);
    float val2 = *(data4+ridx0);
    float val3 = *(data5+ridx0);
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 512; ridx1++) {
      for (int ridx2 = 0; ridx2 < 6; ridx2++) {
        int alu0 = ((ridx0*36)+(ridx1*2304)+(ridx2*6));
        int alu1 = (((ridx2>>1)*3)+(ridx0*9)+(ridx1*576));
        int alu2 = (alu1+1);
        int alu3 = (alu1+2);
        float val4 = *(data6+alu2);
        float val5 = *(data6+alu3);
        float val6 = *(data6+alu1);
        float val7 = *(data7+alu2);
        float alu4 = (1/val7);
        float val8 = *(data7+alu3);
        float alu5 = (1/val8);
        float val9 = *(data7+alu1);
        float alu6 = (1/val9);
        float val10 = *(data8+alu2);
        float val11 = *(data8+alu3);
        float val12 = *(data8+alu1);
        float2 val13 = *((float2*)(data1+alu0+2));
        float2 val14 = *((float2*)(data1+alu0+4));
        float2 val15 = *((float2*)(data1+alu0));
        acc0 = (acc0+((float)((((((val15[0]-val0)*val1*val2)+val3)!=val6)!=1))*alu6*val12)+((float)((((((val15[1]-val0)*val1*val2)+val3)!=val6)!=1))*alu6*val12)+((float)((((((val13[0]-val0)*val1*val2)+val3)!=val4)!=1))*alu4*val10)+((float)((((((val13[1]-val0)*val1*val2)+val3)!=val4)!=1))*alu4*val10)+((float)((((((val14[0]-val0)*val1*val2)+val3)!=val5)!=1))*alu5*val11)+((float)((((((val14[1]-val0)*val1*val2)+val3)!=val5)!=1))*alu5*val11));
      }
    }
    *(data0+ridx0) = acc0;
  }
}

void E_512_64_6_2_3n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8, float* restrict data9, float* restrict data10) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      for (int ridx2 = 0; ridx2 < 6; ridx2++) {
        int alu0 = (((ridx2>>1)*3)+(ridx0*576)+(ridx1*9));
        for (int ridx3 = 0; ridx3 < 2; ridx3++) {
          int alu1 = (ridx3*3);
          int alu2 = ((ridx0*2304)+(ridx1*36)+(ridx2*6)+alu1);
          int alu3 = (alu2+1);
          int alu4 = (alu2+2);
          int alu5 = (alu0+((alu1+1)>>1));
          int alu6 = ((alu1>>1)+alu0);
          int alu7 = (alu6+1);
          float val0 = *(data1+alu3);
          float val1 = *(data1+alu4);
          float val2 = *(data1+alu2);
          float val3 = *(data2+ridx1);
          float alu8 = (val0-val3);
          float alu9 = (val1-val3);
          float alu10 = (val2-val3);
          float val4 = *(data3+ridx1);
          float val5 = *(data4+ridx1);
          float val6 = *(data5+ridx1);
          float val7 = *(data6+ridx1);
          float val8 = *(data7+alu5);
          float val9 = *(data7+alu7);
          float val10 = *(data7+alu6);
          float val11 = *(data8+alu5);
          float val12 = *(data8+alu7);
          float val13 = *(data8+alu6);
          float val14 = *(data9+alu5);
          float val15 = *(data9+alu7);
          float val16 = *(data9+alu6);
          float val17 = *(data10+ridx1);
          *(data0+alu3) = ((float)((0.0f<val0))*((alu8*val4*2.0f)+(val5*val6*(float)(((((alu8*val5*val6)+val7)!=val8)!=1))*(1/val11)*val14)+val17));
          *(data0+alu4) = ((float)((0.0f<val1))*((alu9*val4*2.0f)+(val5*val6*(float)(((((alu9*val5*val6)+val7)!=val9)!=1))*(1/val12)*val15)+val17));
          *(data0+alu2) = ((float)((0.0f<val2))*((alu10*val4*2.0f)+(val5*val6*(float)(((((alu10*val5*val6)+val7)!=val10)!=1))*(1/val13)*val16)+val17));
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_16_4n10(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 16; ridx0++) {
    int alu0 = (ridx0<<2);
    float4 val0 = *((float4*)(data0+alu0));
    float4 val1 = *((float4*)(data1+alu0));
    *((float4*)(data0+alu0)) = (float4){((val0[0]*0.9f)+(val1[0]*0.09999999999999998f)),((val0[1]*0.9f)+(val1[1]*0.09999999999999998f)),((val0[2]*0.9f)+(val1[2]*0.09999999999999998f)),((val0[3]*0.9f)+(val1[3]*0.09999999999999998f))};
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_16_4n11(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 16; ridx0++) {
    int alu0 = (ridx0<<2);
    float4 val0 = *((float4*)(data0+alu0));
    float4 val1 = *((float4*)(data1+alu0));
    *((float4*)(data0+alu0)) = (float4){((val0[0]*0.999f)+(val1[0]*val1[0]*0.0010000000000000009f)),((val0[1]*0.999f)+(val1[1]*val1[1]*0.0010000000000000009f)),((val0[2]*0.999f)+(val1[2]*val1[2]*0.0010000000000000009f)),((val0[3]*0.999f)+(val1[3]*val1[3]*0.0010000000000000009f))};
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r3_64_512_9_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 512; ridx1++) {
      for (int ridx2 = 0; ridx2 < 9; ridx2++) {
        float4 val0 = *((float4*)(data1+(ridx0*36)+(ridx1*2304)+(ridx2<<2)));
        acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
      }
    }
    float val1 = *(data0+ridx0);
    float alu0 = ((val1*0.9f)+(acc0*0.09999999999999998f));
    *(data0+ridx0) = alu0;
    float val2 = *(data2+ridx0);
    float alu1 = ((val2*0.999f)+(acc0*acc0*0.0010000000000000009f));
    *(data2+ridx0) = alu1;
    float val3 = *(data3+ridx0);
    float val4 = *(data4+0);
    float val5 = *(data5+0);
    float val6 = *(data6+0);
    *(data3+ridx0) = (val3-(val4*alu0*(1/(val5*(__builtin_sqrtf((alu1*(1/val6)))+1e-08f)))));
  }
}

void r_512_64_12_3_16_3_3_4(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      for (int ridx2 = 0; ridx2 < 12; ridx2++) {
        for (int ridx3 = 0; ridx3 < 3; ridx3++) {
          int alu0 = (ridx3*3);
          int alu1 = ((ridx0*20736)+(ridx1*324)+(ridx2*27)+alu0);
          float acc0 = 0.0f;
          float acc1 = 0.0f;
          float acc2 = 0.0f;
          float acc3 = 0.0f;
          float acc4 = 0.0f;
          float acc5 = 0.0f;
          float acc6 = 0.0f;
          float acc7 = 0.0f;
          float acc8 = 0.0f;
          for (int ridx4 = 0; ridx4 < 16; ridx4++) {
            int alu2 = ((ridx1*9)+alu0+(ridx4*2304));
            int alu3 = ((ridx0*2304)+(ridx2*3)+(ridx4*144));
            float val0 = *(data1+alu2+1);
            float val1 = *(data1+alu2+2);
            float val2 = *(data1+alu2+576);
            float val3 = *(data1+alu2+577);
            float val4 = *(data1+alu2+578);
            float val5 = *(data1+alu2+1152);
            float val6 = *(data1+alu2+1153);
            float val7 = *(data1+alu2+1154);
            float val8 = *(data1+alu2+1728);
            float val9 = *(data1+alu2+1729);
            float val10 = *(data1+alu2+1730);
            float val11 = *(data1+alu2);
            float val12 = *(data2+alu3+1);
            float val13 = *(data2+alu3+2);
            float val14 = *(data2+alu3+36);
            float val15 = *(data2+alu3+37);
            float val16 = *(data2+alu3+38);
            float val17 = *(data2+alu3+72);
            float val18 = *(data2+alu3+73);
            float val19 = *(data2+alu3+74);
            float val20 = *(data2+alu3+108);
            float val21 = *(data2+alu3+109);
            acc3 = (acc3+(val11*val12)+(val2*val15)+(val5*val18)+(val8*val21));
            acc4 = (acc4+(val0*val12)+(val3*val15)+(val6*val18)+(val9*val21));
            acc5 = (acc5+(val1*val12)+(val4*val15)+(val7*val18)+(val10*val21));
            float val22 = *(data2+alu3+110);
            acc6 = (acc6+(val11*val13)+(val2*val16)+(val5*val19)+(val8*val22));
            acc7 = (acc7+(val0*val13)+(val3*val16)+(val6*val19)+(val9*val22));
            acc8 = (acc8+(val1*val13)+(val4*val16)+(val7*val19)+(val10*val22));
            float val23 = *(data2+alu3);
            acc0 = (acc0+(val11*val23)+(val2*val14)+(val5*val17)+(val8*val20));
            acc1 = (acc1+(val0*val23)+(val3*val14)+(val6*val17)+(val9*val20));
            acc2 = (acc2+(val1*val23)+(val4*val14)+(val7*val17)+(val10*val20));
          }
          *(data0+alu1+1) = acc1;
          *(data0+alu1+2) = acc2;
          *(data0+alu1+9) = acc3;
          *(data0+alu1+10) = acc4;
          *(data0+alu1+11) = acc5;
          *(data0+alu1+18) = acc6;
          *(data0+alu1+19) = acc7;
          *(data0+alu1+20) = acc8;
          *(data0+alu1) = acc0;
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_16_4n12(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5) {
  for (int ridx0 = 0; ridx0 < 16; ridx0++) {
    int alu0 = (ridx0<<2);
    float val0 = *(data1+0);
    float val1 = *(data3+0);
    float val2 = *(data5+0);
    float alu1 = (1/val2);
    float4 val3 = *((float4*)(data0+alu0));
    float4 val4 = *((float4*)(data2+alu0));
    float4 val5 = *((float4*)(data4+alu0));
    *((float4*)(data0+alu0)) = (float4){(val3[0]-(val0*val4[0]*(1/(val1*(__builtin_sqrtf((val5[0]*alu1))+1e-08f))))),(val3[1]-(val0*val4[1]*(1/(val1*(__builtin_sqrtf((val5[1]*alu1))+1e-08f))))),(val3[2]-(val0*val4[2]*(1/(val1*(__builtin_sqrtf((val5[2]*alu1))+1e-08f))))),(val3[3]-(val0*val4[3]*(1/(val1*(__builtin_sqrtf((val5[3]*alu1))+1e-08f)))))};
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_512_64_8_2_4_4_4(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      for (int ridx2 = 0; ridx2 < 8; ridx2++) {
        for (int ridx3 = 0; ridx3 < 2; ridx3++) {
          int alu0 = (ridx3<<2);
          int alu1 = (alu0+7);
          int alu2 = (alu0+8);
          int alu3 = (alu1%9);
          int alu4 = (alu2%9);
          int alu5 = ((ridx0<<12)+(ridx1<<6)+(ridx2<<3)+alu0);
          float acc0 = 0.0f;
          float acc1 = 0.0f;
          float acc2 = 0.0f;
          float acc3 = 0.0f;
          for (int ridx4 = 0; ridx4 < 4; ridx4++) {
            int alu6 = (ridx2+(ridx4<<3));
            int alu7 = (alu6%9);
            int alu8 = ((ridx0*20736)+(ridx1*324)+((alu6/9)*3)+(alu7*54));
            int alu9 = ((ridx3*36)+alu8);
            int alu10 = ((alu2/9)+alu8+(alu4*9));
            _Bool alu11 = ((alu6<27)&(alu7<6));
            _Bool alu12 = (alu11&(alu4<6));
            _Bool alu13 = (alu11&(ridx3<1));
            float val0 = (alu13?*(data2+alu8+18):0.0f);
            float val1 = (alu13?*(data2+alu8+19):0.0f);
            float val2 = (alu13?*(data2+alu8+27):0.0f);
            float val3 = ((alu11&(alu3<6))?*(data2+(alu1/9)+alu8+(alu3*9)+1):0.0f);
            float val4 = (alu12?*(data2+alu10+1):0.0f);
            float val5 = (alu11?*(data2+alu9+1):0.0f);
            float val6 = (alu11?*(data2+alu9+2):0.0f);
            float val7 = (alu11?*(data2+alu9+9):0.0f);
            acc1 = (acc1+val7+val5+val4);
            float val8 = (alu11?*(data2+alu9+10):0.0f);
            acc2 = (acc2+val0+val8+val6);
            float val9 = (alu11?*(data2+alu9+11):0.0f);
            acc3 = (acc3+val2+val1+val9);
            float val10 = (alu12?*(data2+alu10):0.0f);
            float val11 = (alu11?*(data2+alu9):0.0f);
            acc0 = (acc0+val11+val10+val3);
          }
          float4 val12 = *((float4*)(data1+alu5));
          *((float4*)(data0+alu5)) = (float4){((float)((0.0f<val12[0]))*acc0),((float)((0.0f<val12[1]))*acc1),((float)((0.0f<val12[2]))*acc2),((float)((0.0f<val12[3]))*acc3)};
        }
      }
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r3_16_64_3_512_6_4_3_6n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7) {
  for (int ridx0 = 0; ridx0 < 16; ridx0++) {
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      for (int ridx2 = 0; ridx2 < 3; ridx2++) {
        int alu0 = ((ridx0*2304)+(ridx1*9)+(ridx2*3));
        int alu1 = (alu0+1);
        int alu2 = (alu0+2);
        int alu3 = (alu0+576);
        int alu4 = (alu0+577);
        int alu5 = (alu0+578);
        int alu6 = (alu0+1152);
        int alu7 = (alu0+1153);
        int alu8 = (alu0+1154);
        int alu9 = (alu0+1728);
        int alu10 = (alu0+1729);
        int alu11 = (alu0+1730);
        float acc0 = 0.0f;
        float acc1 = 0.0f;
        float acc2 = 0.0f;
        float acc3 = 0.0f;
        float acc4 = 0.0f;
        float acc5 = 0.0f;
        float acc6 = 0.0f;
        float acc7 = 0.0f;
        float acc8 = 0.0f;
        float acc9 = 0.0f;
        float acc10 = 0.0f;
        float acc11 = 0.0f;
        for (int ridx3 = 0; ridx3 < 512; ridx3++) {
          for (int ridx4 = 0; ridx4 < 6; ridx4++) {
            int alu12 = ((ridx1<<6)+(ridx2<<3)+(ridx3<<12)+(ridx4<<3));
            int alu13 = ((ridx0*144)+(ridx3*2304)+(ridx4*6));
            float2 val0 = *((float2*)(data2+alu13+2));
            float2 val1 = *((float2*)(data2+alu13+4));
            float2 val2 = *((float2*)(data2+alu13+36));
            float2 val3 = *((float2*)(data2+alu13+38));
            float2 val4 = *((float2*)(data2+alu13+40));
            float2 val5 = *((float2*)(data2+alu13+72));
            float2 val6 = *((float2*)(data2+alu13+74));
            float2 val7 = *((float2*)(data2+alu13+76));
            float2 val8 = *((float2*)(data2+alu13+108));
            float2 val9 = *((float2*)(data2+alu13+110));
            float2 val10 = *((float2*)(data2+alu13+112));
            float2 val11 = *((float2*)(data2+alu13));
            float4 val12 = *((float4*)(data1+alu12+4));
            float4 val13 = *((float4*)(data1+alu12));
            acc0 = (acc0+(val13[0]*val11[0])+(val13[1]*val11[1])+(val13[2]*val0[0])+(val13[3]*val0[1])+(val12[0]*val1[0])+(val12[1]*val1[1]));
            acc1 = (acc1+(val13[1]*val11[0])+(val13[2]*val11[1])+(val13[3]*val0[0])+(val12[0]*val0[1])+(val12[1]*val1[0])+(val12[2]*val1[1]));
            acc2 = (acc2+(val13[2]*val11[0])+(val13[3]*val11[1])+(val12[0]*val0[0])+(val12[1]*val0[1])+(val12[2]*val1[0])+(val12[3]*val1[1]));
            acc3 = (acc3+(val13[0]*val2[0])+(val13[1]*val2[1])+(val13[2]*val3[0])+(val13[3]*val3[1])+(val12[0]*val4[0])+(val12[1]*val4[1]));
            acc4 = (acc4+(val13[1]*val2[0])+(val13[2]*val2[1])+(val13[3]*val3[0])+(val12[0]*val3[1])+(val12[1]*val4[0])+(val12[2]*val4[1]));
            acc5 = (acc5+(val13[2]*val2[0])+(val13[3]*val2[1])+(val12[0]*val3[0])+(val12[1]*val3[1])+(val12[2]*val4[0])+(val12[3]*val4[1]));
            acc6 = (acc6+(val13[0]*val5[0])+(val13[1]*val5[1])+(val13[2]*val6[0])+(val13[3]*val6[1])+(val12[0]*val7[0])+(val12[1]*val7[1]));
            acc7 = (acc7+(val13[1]*val5[0])+(val13[2]*val5[1])+(val13[3]*val6[0])+(val12[0]*val6[1])+(val12[1]*val7[0])+(val12[2]*val7[1]));
            acc8 = (acc8+(val13[2]*val5[0])+(val13[3]*val5[1])+(val12[0]*val6[0])+(val12[1]*val6[1])+(val12[2]*val7[0])+(val12[3]*val7[1]));
            acc9 = (acc9+(val13[0]*val8[0])+(val13[1]*val8[1])+(val13[2]*val9[0])+(val13[3]*val9[1])+(val12[0]*val10[0])+(val12[1]*val10[1]));
            acc10 = (acc10+(val13[1]*val8[0])+(val13[2]*val8[1])+(val13[3]*val9[0])+(val12[0]*val9[1])+(val12[1]*val10[0])+(val12[2]*val10[1]));
            acc11 = (acc11+(val13[2]*val8[0])+(val13[3]*val8[1])+(val12[0]*val9[0])+(val12[1]*val9[1])+(val12[2]*val10[0])+(val12[3]*val10[1]));
          }
        }
        float val14 = *(data0+alu1);
        float alu14 = ((val14*0.9f)+(acc1*0.09999999999999998f));
        *(data0+alu1) = alu14;
        float val15 = *(data0+alu2);
        float alu15 = ((val15*0.9f)+(acc2*0.09999999999999998f));
        *(data0+alu2) = alu15;
        float val16 = *(data0+alu3);
        float alu16 = ((val16*0.9f)+(acc3*0.09999999999999998f));
        *(data0+alu3) = alu16;
        float val17 = *(data0+alu4);
        float alu17 = ((val17*0.9f)+(acc4*0.09999999999999998f));
        *(data0+alu4) = alu17;
        float val18 = *(data0+alu5);
        float alu18 = ((val18*0.9f)+(acc5*0.09999999999999998f));
        *(data0+alu5) = alu18;
        float val19 = *(data0+alu6);
        float alu19 = ((val19*0.9f)+(acc6*0.09999999999999998f));
        *(data0+alu6) = alu19;
        float val20 = *(data0+alu7);
        float alu20 = ((val20*0.9f)+(acc7*0.09999999999999998f));
        *(data0+alu7) = alu20;
        float val21 = *(data0+alu8);
        float alu21 = ((val21*0.9f)+(acc8*0.09999999999999998f));
        *(data0+alu8) = alu21;
        float val22 = *(data0+alu9);
        float alu22 = ((val22*0.9f)+(acc9*0.09999999999999998f));
        *(data0+alu9) = alu22;
        float val23 = *(data0+alu10);
        float alu23 = ((val23*0.9f)+(acc10*0.09999999999999998f));
        *(data0+alu10) = alu23;
        float val24 = *(data0+alu11);
        float alu24 = ((val24*0.9f)+(acc11*0.09999999999999998f));
        *(data0+alu11) = alu24;
        float val25 = *(data0+alu0);
        float alu25 = ((val25*0.9f)+(acc0*0.09999999999999998f));
        *(data0+alu0) = alu25;
        float val26 = *(data3+alu1);
        float alu26 = ((val26*0.999f)+(acc1*acc1*0.0010000000000000009f));
        *(data3+alu1) = alu26;
        float val27 = *(data3+alu2);
        float alu27 = ((val27*0.999f)+(acc2*acc2*0.0010000000000000009f));
        *(data3+alu2) = alu27;
        float val28 = *(data3+alu3);
        float alu28 = ((val28*0.999f)+(acc3*acc3*0.0010000000000000009f));
        *(data3+alu3) = alu28;
        float val29 = *(data3+alu4);
        float alu29 = ((val29*0.999f)+(acc4*acc4*0.0010000000000000009f));
        *(data3+alu4) = alu29;
        float val30 = *(data3+alu5);
        float alu30 = ((val30*0.999f)+(acc5*acc5*0.0010000000000000009f));
        *(data3+alu5) = alu30;
        float val31 = *(data3+alu6);
        float alu31 = ((val31*0.999f)+(acc6*acc6*0.0010000000000000009f));
        *(data3+alu6) = alu31;
        float val32 = *(data3+alu7);
        float alu32 = ((val32*0.999f)+(acc7*acc7*0.0010000000000000009f));
        *(data3+alu7) = alu32;
        float val33 = *(data3+alu8);
        float alu33 = ((val33*0.999f)+(acc8*acc8*0.0010000000000000009f));
        *(data3+alu8) = alu33;
        float val34 = *(data3+alu9);
        float alu34 = ((val34*0.999f)+(acc9*acc9*0.0010000000000000009f));
        *(data3+alu9) = alu34;
        float val35 = *(data3+alu10);
        float alu35 = ((val35*0.999f)+(acc10*acc10*0.0010000000000000009f));
        *(data3+alu10) = alu35;
        float val36 = *(data3+alu11);
        float alu36 = ((val36*0.999f)+(acc11*acc11*0.0010000000000000009f));
        *(data3+alu11) = alu36;
        float val37 = *(data3+alu0);
        float alu37 = ((val37*0.999f)+(acc0*acc0*0.0010000000000000009f));
        *(data3+alu0) = alu37;
        float val38 = *(data4+alu1);
        float val39 = *(data4+alu2);
        float val40 = *(data4+alu3);
        float val41 = *(data4+alu4);
        float val42 = *(data4+alu5);
        float val43 = *(data4+alu6);
        float val44 = *(data4+alu7);
        float val45 = *(data4+alu8);
        float val46 = *(data4+alu9);
        float val47 = *(data4+alu10);
        float val48 = *(data4+alu11);
        float val49 = *(data4+alu0);
        float val50 = *(data5+0);
        float val51 = *(data6+0);
        float val52 = *(data7+0);
        float alu38 = (1/val52);
        *(data4+alu1) = (val38-(val50*alu14*(1/(val51*(__builtin_sqrtf((alu26*alu38))+1e-08f)))));
        *(data4+alu2) = (val39-(val50*alu15*(1/(val51*(__builtin_sqrtf((alu27*alu38))+1e-08f)))));
        *(data4+alu3) = (val40-(val50*alu16*(1/(val51*(__builtin_sqrtf((alu28*alu38))+1e-08f)))));
        *(data4+alu4) = (val41-(val50*alu17*(1/(val51*(__builtin_sqrtf((alu29*alu38))+1e-08f)))));
        *(data4+alu5) = (val42-(val50*alu18*(1/(val51*(__builtin_sqrtf((alu30*alu38))+1e-08f)))));
        *(data4+alu6) = (val43-(val50*alu19*(1/(val51*(__builtin_sqrtf((alu31*alu38))+1e-08f)))));
        *(data4+alu7) = (val44-(val50*alu20*(1/(val51*(__builtin_sqrtf((alu32*alu38))+1e-08f)))));
        *(data4+alu8) = (val45-(val50*alu21*(1/(val51*(__builtin_sqrtf((alu33*alu38))+1e-08f)))));
        *(data4+alu9) = (val46-(val50*alu22*(1/(val51*(__builtin_sqrtf((alu34*alu38))+1e-08f)))));
        *(data4+alu10) = (val47-(val50*alu23*(1/(val51*(__builtin_sqrtf((alu35*alu38))+1e-08f)))));
        *(data4+alu11) = (val48-(val50*alu24*(1/(val51*(__builtin_sqrtf((alu36*alu38))+1e-08f)))));
        *(data4+alu0) = (val49-(val50*alu25*(1/(val51*(__builtin_sqrtf((alu37*alu38))+1e-08f)))));
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_512_32_16_3_16_4_3_4(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 32; ridx1++) {
      for (int ridx2 = 0; ridx2 < 16; ridx2++) {
        for (int ridx3 = 0; ridx3 < 3; ridx3++) {
          int alu0 = (ridx3*3);
          int alu1 = ((ridx0*18432)+(ridx1*576)+(ridx2*36)+alu0);
          float acc0 = 0.0f;
          float acc1 = 0.0f;
          float acc2 = 0.0f;
          float acc3 = 0.0f;
          float acc4 = 0.0f;
          float acc5 = 0.0f;
          float acc6 = 0.0f;
          float acc7 = 0.0f;
          float acc8 = 0.0f;
          float acc9 = 0.0f;
          float acc10 = 0.0f;
          float acc11 = 0.0f;
          for (int ridx4 = 0; ridx4 < 16; ridx4++) {
            int alu2 = ((ridx1*9)+alu0+(ridx4*1152));
            int alu3 = ((ridx0<<12)+(ridx2<<2)+(ridx4<<8));
            float val0 = *(data1+alu2+1);
            float val1 = *(data1+alu2+2);
            float val2 = *(data1+alu2+288);
            float val3 = *(data1+alu2+289);
            float val4 = *(data1+alu2+290);
            float val5 = *(data1+alu2+576);
            float val6 = *(data1+alu2+577);
            float val7 = *(data1+alu2+578);
            float val8 = *(data1+alu2+864);
            float val9 = *(data1+alu2+865);
            float val10 = *(data1+alu2+866);
            float val11 = *(data1+alu2);
            float4 val12 = *((float4*)(data2+alu3+64));
            float4 val13 = *((float4*)(data2+alu3+128));
            float4 val14 = *((float4*)(data2+alu3+192));
            float4 val15 = *((float4*)(data2+alu3));
            acc0 = (acc0+(val11*val15[0])+(val2*val12[0])+(val5*val13[0])+(val8*val14[0]));
            acc1 = (acc1+(val0*val15[0])+(val3*val12[0])+(val6*val13[0])+(val9*val14[0]));
            acc2 = (acc2+(val1*val15[0])+(val4*val12[0])+(val7*val13[0])+(val10*val14[0]));
            acc3 = (acc3+(val11*val15[1])+(val2*val12[1])+(val5*val13[1])+(val8*val14[1]));
            acc4 = (acc4+(val0*val15[1])+(val3*val12[1])+(val6*val13[1])+(val9*val14[1]));
            acc5 = (acc5+(val1*val15[1])+(val4*val12[1])+(val7*val13[1])+(val10*val14[1]));
            acc6 = (acc6+(val11*val15[2])+(val2*val12[2])+(val5*val13[2])+(val8*val14[2]));
            acc7 = (acc7+(val0*val15[2])+(val3*val12[2])+(val6*val13[2])+(val9*val14[2]));
            acc8 = (acc8+(val1*val15[2])+(val4*val12[2])+(val7*val13[2])+(val10*val14[2]));
            acc9 = (acc9+(val11*val15[3])+(val2*val12[3])+(val5*val13[3])+(val8*val14[3]));
            acc10 = (acc10+(val0*val15[3])+(val3*val12[3])+(val6*val13[3])+(val9*val14[3]));
            acc11 = (acc11+(val1*val15[3])+(val4*val12[3])+(val7*val13[3])+(val10*val14[3]));
          }
          *(data0+alu1+1) = acc1;
          *(data0+alu1+2) = acc2;
          *(data0+alu1+9) = acc3;
          *(data0+alu1+10) = acc4;
          *(data0+alu1+11) = acc5;
          *(data0+alu1+18) = acc6;
          *(data0+alu1+19) = acc7;
          *(data0+alu1+20) = acc8;
          *(data0+alu1+27) = acc9;
          *(data0+alu1+28) = acc10;
          *(data0+alu1+29) = acc11;
          *(data0+alu1) = acc0;
        }
      }
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_16_32_3_128_4_8_4_3_8(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 16; ridx0++) {
    for (int ridx1 = 0; ridx1 < 32; ridx1++) {
      for (int ridx2 = 0; ridx2 < 3; ridx2++) {
        for (int ridx3 = 0; ridx3 < 128; ridx3++) {
          int alu0 = ((ridx0*147456)+(ridx1*1152)+(ridx2*384)+ridx3);
          float acc0 = 0.0f;
          float acc1 = 0.0f;
          float acc2 = 0.0f;
          float acc3 = 0.0f;
          float acc4 = 0.0f;
          float acc5 = 0.0f;
          float acc6 = 0.0f;
          float acc7 = 0.0f;
          float acc8 = 0.0f;
          float acc9 = 0.0f;
          float acc10 = 0.0f;
          float acc11 = 0.0f;
          for (int ridx4 = 0; ridx4 < 4; ridx4++) {
            for (int ridx5 = 0; ridx5 < 8; ridx5++) {
              int alu1 = ((ridx1*100)+(ridx2*10)+(ridx3*12800)+(ridx4*3200)+(ridx5*10));
              int alu2 = ((ridx0<<8)+(ridx3<<14)+(ridx4<<12)+(ridx5<<3));
              float2 val0 = *((float2*)(data1+alu1+2));
              float2 val1 = *((float2*)(data1+alu1+4));
              float2 val2 = *((float2*)(data1+alu1+6));
              float2 val3 = *((float2*)(data1+alu1+8));
              float2 val4 = *((float2*)(data1+alu1));
              float4 val5 = *((float4*)(data2+alu2+4));
              float4 val6 = *((float4*)(data2+alu2+64));
              float4 val7 = *((float4*)(data2+alu2+68));
              acc3 = (acc3+(val4[0]*val6[0])+(val4[1]*val6[1])+(val0[0]*val6[2])+(val0[1]*val6[3])+(val1[0]*val7[0])+(val1[1]*val7[1])+(val2[0]*val7[2])+(val2[1]*val7[3]));
              acc4 = (acc4+(val4[1]*val6[0])+(val0[0]*val6[1])+(val0[1]*val6[2])+(val1[0]*val6[3])+(val1[1]*val7[0])+(val2[0]*val7[1])+(val2[1]*val7[2])+(val3[0]*val7[3]));
              acc5 = (acc5+(val0[0]*val6[0])+(val0[1]*val6[1])+(val1[0]*val6[2])+(val1[1]*val6[3])+(val2[0]*val7[0])+(val2[1]*val7[1])+(val3[0]*val7[2])+(val3[1]*val7[3]));
              float4 val8 = *((float4*)(data2+alu2+128));
              float4 val9 = *((float4*)(data2+alu2+132));
              acc6 = (acc6+(val4[0]*val8[0])+(val4[1]*val8[1])+(val0[0]*val8[2])+(val0[1]*val8[3])+(val1[0]*val9[0])+(val1[1]*val9[1])+(val2[0]*val9[2])+(val2[1]*val9[3]));
              acc7 = (acc7+(val4[1]*val8[0])+(val0[0]*val8[1])+(val0[1]*val8[2])+(val1[0]*val8[3])+(val1[1]*val9[0])+(val2[0]*val9[1])+(val2[1]*val9[2])+(val3[0]*val9[3]));
              acc8 = (acc8+(val0[0]*val8[0])+(val0[1]*val8[1])+(val1[0]*val8[2])+(val1[1]*val8[3])+(val2[0]*val9[0])+(val2[1]*val9[1])+(val3[0]*val9[2])+(val3[1]*val9[3]));
              float4 val10 = *((float4*)(data2+alu2+192));
              float4 val11 = *((float4*)(data2+alu2+196));
              acc9 = (acc9+(val4[0]*val10[0])+(val4[1]*val10[1])+(val0[0]*val10[2])+(val0[1]*val10[3])+(val1[0]*val11[0])+(val1[1]*val11[1])+(val2[0]*val11[2])+(val2[1]*val11[3]));
              acc10 = (acc10+(val4[1]*val10[0])+(val0[0]*val10[1])+(val0[1]*val10[2])+(val1[0]*val10[3])+(val1[1]*val11[0])+(val2[0]*val11[1])+(val2[1]*val11[2])+(val3[0]*val11[3]));
              acc11 = (acc11+(val0[0]*val10[0])+(val0[1]*val10[1])+(val1[0]*val10[2])+(val1[1]*val10[3])+(val2[0]*val11[0])+(val2[1]*val11[1])+(val3[0]*val11[2])+(val3[1]*val11[3]));
              float4 val12 = *((float4*)(data2+alu2));
              acc0 = (acc0+(val4[0]*val12[0])+(val4[1]*val12[1])+(val0[0]*val12[2])+(val0[1]*val12[3])+(val1[0]*val5[0])+(val1[1]*val5[1])+(val2[0]*val5[2])+(val2[1]*val5[3]));
              acc1 = (acc1+(val4[1]*val12[0])+(val0[0]*val12[1])+(val0[1]*val12[2])+(val1[0]*val12[3])+(val1[1]*val5[0])+(val2[0]*val5[1])+(val2[1]*val5[2])+(val3[0]*val5[3]));
              acc2 = (acc2+(val0[0]*val12[0])+(val0[1]*val12[1])+(val1[0]*val12[2])+(val1[1]*val12[3])+(val2[0]*val5[0])+(val2[1]*val5[1])+(val3[0]*val5[2])+(val3[1]*val5[3]));
            }
          }
          *(data0+alu0+128) = acc1;
          *(data0+alu0+256) = acc2;
          *(data0+alu0+36864) = acc3;
          *(data0+alu0+36992) = acc4;
          *(data0+alu0+37120) = acc5;
          *(data0+alu0+73728) = acc6;
          *(data0+alu0+73856) = acc7;
          *(data0+alu0+73984) = acc8;
          *(data0+alu0+110592) = acc9;
          *(data0+alu0+110720) = acc10;
          *(data0+alu0+110848) = acc11;
          *(data0+alu0) = acc0;
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_64_256_2_16_4(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    for (int ridx1 = 0; ridx1 < 256; ridx1++) {
      float acc0 = 0.0f;
      for (int ridx2 = 0; ridx2 < 2; ridx2++) {
        for (int ridx3 = 0; ridx3 < 16; ridx3++) {
          float4 val0 = *((float4*)(data1+(ridx0<<6)+(ridx1<<13)+(ridx2<<12)+(ridx3<<2)));
          acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
        }
      }
      *(data0+(ridx0<<8)+ridx1) = acc0;
    }
  }
}

void r_512_32_10_10_4_4(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 32; ridx1++) {
      for (int ridx2 = 0; ridx2 < 10; ridx2++) {
        for (int ridx3 = 0; ridx3 < 10; ridx3++) {
          int alu0 = (ridx3+9);
          int alu1 = (ridx3+10);
          int alu2 = (alu0%11);
          int alu3 = (alu1%11);
          float acc0 = 0.0f;
          for (int ridx4 = 0; ridx4 < 4; ridx4++) {
            int alu4 = (ridx2+(ridx4*10));
            int alu5 = (alu4%11);
            int alu6 = ((ridx0*18432)+(ridx1*576)+((alu4/11)*3)+(alu5*72));
            _Bool alu7 = ((alu4<33)&(alu5<8));
            float val0 = ((alu7&(alu3<8))?*(data1+alu6+(alu1/11)+(alu3*9)):0.0f);
            float val1 = ((alu7&(ridx3<8))?*(data1+alu6+(ridx3*9)):0.0f);
            float val2 = ((alu7&(alu2<8))?*(data1+(alu0/11)+alu6+(alu2*9)+1):0.0f);
            acc0 = (acc0+val1+val0+val2);
          }
          *(data0+(ridx0*3200)+(ridx1*100)+(ridx2*10)+ridx3) = acc0;
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r3_6144_32_3_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 6144; ridx0++) {
    int alu0 = (ridx0*3);
    int alu1 = (alu0+1);
    int alu2 = (alu0+2);
    float acc0 = 0.0f;
    float acc1 = 0.0f;
    float acc2 = 0.0f;
    for (int ridx1 = 0; ridx1 < 32; ridx1++) {
      int alu3 = ((ridx0*384)+(ridx1<<2));
      float4 val0 = *((float4*)(data1+alu3+128));
      acc1 = (acc1+val0[0]+val0[1]+val0[2]+val0[3]);
      float4 val1 = *((float4*)(data1+alu3+256));
      acc2 = (acc2+val1[0]+val1[1]+val1[2]+val1[3]);
      float4 val2 = *((float4*)(data1+alu3));
      acc0 = (acc0+val2[0]+val2[1]+val2[2]+val2[3]);
    }
    float val3 = *(data0+alu1);
    float alu4 = ((val3*0.9f)+(acc1*0.09999999999999998f));
    *(data0+alu1) = alu4;
    float val4 = *(data0+alu2);
    float alu5 = ((val4*0.9f)+(acc2*0.09999999999999998f));
    *(data0+alu2) = alu5;
    float val5 = *(data0+alu0);
    float alu6 = ((val5*0.9f)+(acc0*0.09999999999999998f));
    *(data0+alu0) = alu6;
    float val6 = *(data2+alu1);
    float alu7 = ((val6*0.999f)+(acc1*acc1*0.0010000000000000009f));
    *(data2+alu1) = alu7;
    float val7 = *(data2+alu2);
    float alu8 = ((val7*0.999f)+(acc2*acc2*0.0010000000000000009f));
    *(data2+alu2) = alu8;
    float val8 = *(data2+alu0);
    float alu9 = ((val8*0.999f)+(acc0*acc0*0.0010000000000000009f));
    *(data2+alu0) = alu9;
    float val9 = *(data3+alu1);
    float val10 = *(data3+alu2);
    float val11 = *(data3+alu0);
    float val12 = *(data4+0);
    float val13 = *(data5+0);
    float val14 = *(data6+0);
    float alu10 = (1/val14);
    *(data3+alu1) = (val9-(val12*alu4*(1/(val13*(__builtin_sqrtf((alu7*alu10))+1e-08f)))));
    *(data3+alu2) = (val10-(val12*alu5*(1/(val13*(__builtin_sqrtf((alu8*alu10))+1e-08f)))));
    *(data3+alu0) = (val11-(val12*alu6*(1/(val13*(__builtin_sqrtf((alu9*alu10))+1e-08f)))));
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r3_64_64_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 64; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float4 val0 = *((float4*)(data1+(ridx0<<8)+(ridx1<<2)));
      acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
    }
    float val1 = *(data0+ridx0);
    float alu0 = ((val1*0.9f)+(acc0*0.09999999999999998f));
    *(data0+ridx0) = alu0;
    float val2 = *(data2+ridx0);
    float alu1 = ((val2*0.999f)+(acc0*acc0*0.0010000000000000009f));
    *(data2+ridx0) = alu1;
    float val3 = *(data3+ridx0);
    float val4 = *(data4+0);
    float val5 = *(data5+0);
    float val6 = *(data6+0);
    *(data3+ridx0) = (val3-(val4*alu0*(1/(val5*(__builtin_sqrtf((alu1*(1/val6)))+1e-08f)))));
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_64_2_20_4_20n4(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float val0 = *(data2+ridx0);
    float val1 = *(data3+ridx0);
    float val2 = *(data4+ridx0);
    float val3 = *(data5+ridx0);
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float acc0 = 0.0f;
      float acc1 = 0.0f;
      float acc2 = 0.0f;
      float acc3 = 0.0f;
      for (int ridx2 = 0; ridx2 < 2; ridx2++) {
        for (int ridx3 = 0; ridx3 < 20; ridx3++) {
          int alu0 = ((ridx0*400)+(ridx1*102400)+(ridx2*12800)+(ridx3*20));
          int alu1 = ((ridx0*100)+(ridx1*25600)+(ridx2*3200)+((ridx3>>1)*10));
          int alu2 = (alu1+2);
          int alu3 = (alu1+4);
          int alu4 = (alu1+6);
          int alu5 = (alu1+8);
          int alu6 = (alu1+6400);
          int alu7 = (alu1+6402);
          int alu8 = (alu1+6404);
          int alu9 = (alu1+6406);
          int alu10 = (alu1+6408);
          int alu11 = (alu1+12800);
          int alu12 = (alu1+12802);
          int alu13 = (alu1+12804);
          int alu14 = (alu1+12806);
          int alu15 = (alu1+12808);
          int alu16 = (alu1+19200);
          int alu17 = (alu1+19202);
          int alu18 = (alu1+19204);
          int alu19 = (alu1+19206);
          int alu20 = (alu1+19208);
          float2 val4 = *((float2*)(data6+alu2));
          float2 val5 = *((float2*)(data6+alu3));
          float2 val6 = *((float2*)(data6+alu4));
          float2 val7 = *((float2*)(data6+alu5));
          float2 val8 = *((float2*)(data6+alu6));
          float2 val9 = *((float2*)(data6+alu7));
          float2 val10 = *((float2*)(data6+alu8));
          float2 val11 = *((float2*)(data6+alu9));
          float2 val12 = *((float2*)(data6+alu10));
          float2 val13 = *((float2*)(data6+alu11));
          float2 val14 = *((float2*)(data6+alu12));
          float2 val15 = *((float2*)(data6+alu13));
          float2 val16 = *((float2*)(data6+alu14));
          float2 val17 = *((float2*)(data6+alu15));
          float2 val18 = *((float2*)(data6+alu16));
          float2 val19 = *((float2*)(data6+alu17));
          float2 val20 = *((float2*)(data6+alu18));
          float2 val21 = *((float2*)(data6+alu19));
          float2 val22 = *((float2*)(data6+alu20));
          float2 val23 = *((float2*)(data6+alu1));
          float2 val24 = *((float2*)(data7+alu2));
          float alu21 = (1/val24[0]);
          float alu22 = (1/val24[1]);
          float2 val25 = *((float2*)(data7+alu3));
          float alu23 = (1/val25[0]);
          float alu24 = (1/val25[1]);
          float2 val26 = *((float2*)(data7+alu4));
          float alu25 = (1/val26[0]);
          float alu26 = (1/val26[1]);
          float2 val27 = *((float2*)(data7+alu5));
          float alu27 = (1/val27[0]);
          float alu28 = (1/val27[1]);
          float2 val28 = *((float2*)(data7+alu6));
          float alu29 = (1/val28[0]);
          float alu30 = (1/val28[1]);
          float2 val29 = *((float2*)(data7+alu7));
          float alu31 = (1/val29[0]);
          float alu32 = (1/val29[1]);
          float2 val30 = *((float2*)(data7+alu8));
          float alu33 = (1/val30[0]);
          float alu34 = (1/val30[1]);
          float2 val31 = *((float2*)(data7+alu9));
          float alu35 = (1/val31[0]);
          float alu36 = (1/val31[1]);
          float2 val32 = *((float2*)(data7+alu10));
          float alu37 = (1/val32[0]);
          float alu38 = (1/val32[1]);
          float2 val33 = *((float2*)(data7+alu11));
          float alu39 = (1/val33[0]);
          float alu40 = (1/val33[1]);
          float2 val34 = *((float2*)(data7+alu12));
          float alu41 = (1/val34[0]);
          float alu42 = (1/val34[1]);
          float2 val35 = *((float2*)(data7+alu13));
          float alu43 = (1/val35[0]);
          float alu44 = (1/val35[1]);
          float2 val36 = *((float2*)(data7+alu14));
          float alu45 = (1/val36[0]);
          float alu46 = (1/val36[1]);
          float2 val37 = *((float2*)(data7+alu15));
          float alu47 = (1/val37[0]);
          float alu48 = (1/val37[1]);
          float2 val38 = *((float2*)(data7+alu16));
          float alu49 = (1/val38[0]);
          float alu50 = (1/val38[1]);
          float2 val39 = *((float2*)(data7+alu17));
          float alu51 = (1/val39[0]);
          float alu52 = (1/val39[1]);
          float2 val40 = *((float2*)(data7+alu18));
          float alu53 = (1/val40[0]);
          float alu54 = (1/val40[1]);
          float2 val41 = *((float2*)(data7+alu19));
          float alu55 = (1/val41[0]);
          float alu56 = (1/val41[1]);
          float2 val42 = *((float2*)(data7+alu20));
          float alu57 = (1/val42[0]);
          float alu58 = (1/val42[1]);
          float2 val43 = *((float2*)(data7+alu1));
          float alu59 = (1/val43[0]);
          float alu60 = (1/val43[1]);
          float2 val44 = *((float2*)(data8+alu2));
          float2 val45 = *((float2*)(data8+alu3));
          float2 val46 = *((float2*)(data8+alu4));
          float2 val47 = *((float2*)(data8+alu5));
          float2 val48 = *((float2*)(data8+alu6));
          float2 val49 = *((float2*)(data8+alu7));
          float2 val50 = *((float2*)(data8+alu8));
          float2 val51 = *((float2*)(data8+alu9));
          float2 val52 = *((float2*)(data8+alu10));
          float2 val53 = *((float2*)(data8+alu11));
          float2 val54 = *((float2*)(data8+alu12));
          float2 val55 = *((float2*)(data8+alu13));
          float2 val56 = *((float2*)(data8+alu14));
          float2 val57 = *((float2*)(data8+alu15));
          float2 val58 = *((float2*)(data8+alu16));
          float2 val59 = *((float2*)(data8+alu17));
          float2 val60 = *((float2*)(data8+alu18));
          float2 val61 = *((float2*)(data8+alu19));
          float2 val62 = *((float2*)(data8+alu20));
          float2 val63 = *((float2*)(data8+alu1));
          float4 val64 = *((float4*)(data1+alu0+4));
          float alu61 = ((val64[0]-val0)*val1);
          float alu62 = ((val64[1]-val0)*val1);
          float alu63 = ((val64[2]-val0)*val1);
          float alu64 = ((val64[3]-val0)*val1);
          float4 val65 = *((float4*)(data1+alu0+8));
          float alu65 = ((val65[0]-val0)*val1);
          float alu66 = ((val65[1]-val0)*val1);
          float alu67 = ((val65[2]-val0)*val1);
          float alu68 = ((val65[3]-val0)*val1);
          float4 val66 = *((float4*)(data1+alu0+12));
          float alu69 = ((val66[0]-val0)*val1);
          float alu70 = ((val66[1]-val0)*val1);
          float alu71 = ((val66[2]-val0)*val1);
          float alu72 = ((val66[3]-val0)*val1);
          float4 val67 = *((float4*)(data1+alu0+16));
          float alu73 = ((val67[0]-val0)*val1);
          float alu74 = ((val67[1]-val0)*val1);
          float alu75 = ((val67[2]-val0)*val1);
          float alu76 = ((val67[3]-val0)*val1);
          float4 val68 = *((float4*)(data1+alu0+25600));
          float alu77 = ((val68[0]-val0)*val1);
          float alu78 = ((val68[1]-val0)*val1);
          float alu79 = ((val68[2]-val0)*val1);
          float alu80 = ((val68[3]-val0)*val1);
          float4 val69 = *((float4*)(data1+alu0+25604));
          float alu81 = ((val69[0]-val0)*val1);
          float alu82 = ((val69[1]-val0)*val1);
          float alu83 = ((val69[2]-val0)*val1);
          float alu84 = ((val69[3]-val0)*val1);
          float4 val70 = *((float4*)(data1+alu0+25608));
          float alu85 = ((val70[0]-val0)*val1);
          float alu86 = ((val70[1]-val0)*val1);
          float alu87 = ((val70[2]-val0)*val1);
          float alu88 = ((val70[3]-val0)*val1);
          float4 val71 = *((float4*)(data1+alu0+25612));
          float alu89 = ((val71[0]-val0)*val1);
          float alu90 = ((val71[1]-val0)*val1);
          float alu91 = ((val71[2]-val0)*val1);
          float alu92 = ((val71[3]-val0)*val1);
          float4 val72 = *((float4*)(data1+alu0+25616));
          float alu93 = ((val72[0]-val0)*val1);
          float alu94 = ((val72[1]-val0)*val1);
          float alu95 = ((val72[2]-val0)*val1);
          float alu96 = ((val72[3]-val0)*val1);
          acc1 = (acc1+(alu77*(float)(((((alu77*val2)+val3)!=val8[0])!=1))*alu29*val48[0])+(alu78*(float)(((((alu78*val2)+val3)!=val8[0])!=1))*alu29*val48[0])+(alu79*(float)(((((alu79*val2)+val3)!=val8[1])!=1))*alu30*val48[1])+(alu80*(float)(((((alu80*val2)+val3)!=val8[1])!=1))*alu30*val48[1])+(alu81*(float)(((((alu81*val2)+val3)!=val9[0])!=1))*alu31*val49[0])+(alu82*(float)(((((alu82*val2)+val3)!=val9[0])!=1))*alu31*val49[0])+(alu83*(float)(((((alu83*val2)+val3)!=val9[1])!=1))*alu32*val49[1])+(alu84*(float)(((((alu84*val2)+val3)!=val9[1])!=1))*alu32*val49[1])+(alu85*(float)(((((alu85*val2)+val3)!=val10[0])!=1))*alu33*val50[0])+(alu86*(float)(((((alu86*val2)+val3)!=val10[0])!=1))*alu33*val50[0])+(alu87*(float)(((((alu87*val2)+val3)!=val10[1])!=1))*alu34*val50[1])+(alu88*(float)(((((alu88*val2)+val3)!=val10[1])!=1))*alu34*val50[1])+(alu89*(float)(((((alu89*val2)+val3)!=val11[0])!=1))*alu35*val51[0])+(alu90*(float)(((((alu90*val2)+val3)!=val11[0])!=1))*alu35*val51[0])+(alu91*(float)(((((alu91*val2)+val3)!=val11[1])!=1))*alu36*val51[1])+(alu92*(float)(((((alu92*val2)+val3)!=val11[1])!=1))*alu36*val51[1])+(alu93*(float)(((((alu93*val2)+val3)!=val12[0])!=1))*alu37*val52[0])+(alu94*(float)(((((alu94*val2)+val3)!=val12[0])!=1))*alu37*val52[0])+(alu95*(float)(((((alu95*val2)+val3)!=val12[1])!=1))*alu38*val52[1])+(alu96*(float)(((((alu96*val2)+val3)!=val12[1])!=1))*alu38*val52[1]));
          float4 val73 = *((float4*)(data1+alu0+51200));
          float alu97 = ((val73[0]-val0)*val1);
          float alu98 = ((val73[1]-val0)*val1);
          float alu99 = ((val73[2]-val0)*val1);
          float alu100 = ((val73[3]-val0)*val1);
          float4 val74 = *((float4*)(data1+alu0+51204));
          float alu101 = ((val74[0]-val0)*val1);
          float alu102 = ((val74[1]-val0)*val1);
          float alu103 = ((val74[2]-val0)*val1);
          float alu104 = ((val74[3]-val0)*val1);
          float4 val75 = *((float4*)(data1+alu0+51208));
          float alu105 = ((val75[0]-val0)*val1);
          float alu106 = ((val75[1]-val0)*val1);
          float alu107 = ((val75[2]-val0)*val1);
          float alu108 = ((val75[3]-val0)*val1);
          float4 val76 = *((float4*)(data1+alu0+51212));
          float alu109 = ((val76[0]-val0)*val1);
          float alu110 = ((val76[1]-val0)*val1);
          float alu111 = ((val76[2]-val0)*val1);
          float alu112 = ((val76[3]-val0)*val1);
          float4 val77 = *((float4*)(data1+alu0+51216));
          float alu113 = ((val77[0]-val0)*val1);
          float alu114 = ((val77[1]-val0)*val1);
          float alu115 = ((val77[2]-val0)*val1);
          float alu116 = ((val77[3]-val0)*val1);
          acc2 = (acc2+(alu97*(float)(((((alu97*val2)+val3)!=val13[0])!=1))*alu39*val53[0])+(alu98*(float)(((((alu98*val2)+val3)!=val13[0])!=1))*alu39*val53[0])+(alu99*(float)(((((alu99*val2)+val3)!=val13[1])!=1))*alu40*val53[1])+(alu100*(float)(((((alu100*val2)+val3)!=val13[1])!=1))*alu40*val53[1])+(alu101*(float)(((((alu101*val2)+val3)!=val14[0])!=1))*alu41*val54[0])+(alu102*(float)(((((alu102*val2)+val3)!=val14[0])!=1))*alu41*val54[0])+(alu103*(float)(((((alu103*val2)+val3)!=val14[1])!=1))*alu42*val54[1])+(alu104*(float)(((((alu104*val2)+val3)!=val14[1])!=1))*alu42*val54[1])+(alu105*(float)(((((alu105*val2)+val3)!=val15[0])!=1))*alu43*val55[0])+(alu106*(float)(((((alu106*val2)+val3)!=val15[0])!=1))*alu43*val55[0])+(alu107*(float)(((((alu107*val2)+val3)!=val15[1])!=1))*alu44*val55[1])+(alu108*(float)(((((alu108*val2)+val3)!=val15[1])!=1))*alu44*val55[1])+(alu109*(float)(((((alu109*val2)+val3)!=val16[0])!=1))*alu45*val56[0])+(alu110*(float)(((((alu110*val2)+val3)!=val16[0])!=1))*alu45*val56[0])+(alu111*(float)(((((alu111*val2)+val3)!=val16[1])!=1))*alu46*val56[1])+(alu112*(float)(((((alu112*val2)+val3)!=val16[1])!=1))*alu46*val56[1])+(alu113*(float)(((((alu113*val2)+val3)!=val17[0])!=1))*alu47*val57[0])+(alu114*(float)(((((alu114*val2)+val3)!=val17[0])!=1))*alu47*val57[0])+(alu115*(float)(((((alu115*val2)+val3)!=val17[1])!=1))*alu48*val57[1])+(alu116*(float)(((((alu116*val2)+val3)!=val17[1])!=1))*alu48*val57[1]));
          float4 val78 = *((float4*)(data1+alu0+76800));
          float alu117 = ((val78[0]-val0)*val1);
          float alu118 = ((val78[1]-val0)*val1);
          float alu119 = ((val78[2]-val0)*val1);
          float alu120 = ((val78[3]-val0)*val1);
          float4 val79 = *((float4*)(data1+alu0+76804));
          float alu121 = ((val79[0]-val0)*val1);
          float alu122 = ((val79[1]-val0)*val1);
          float alu123 = ((val79[2]-val0)*val1);
          float alu124 = ((val79[3]-val0)*val1);
          float4 val80 = *((float4*)(data1+alu0+76808));
          float alu125 = ((val80[0]-val0)*val1);
          float alu126 = ((val80[1]-val0)*val1);
          float alu127 = ((val80[2]-val0)*val1);
          float alu128 = ((val80[3]-val0)*val1);
          float4 val81 = *((float4*)(data1+alu0+76812));
          float alu129 = ((val81[0]-val0)*val1);
          float alu130 = ((val81[1]-val0)*val1);
          float alu131 = ((val81[2]-val0)*val1);
          float alu132 = ((val81[3]-val0)*val1);
          float4 val82 = *((float4*)(data1+alu0+76816));
          float alu133 = ((val82[0]-val0)*val1);
          float alu134 = ((val82[1]-val0)*val1);
          float alu135 = ((val82[2]-val0)*val1);
          float alu136 = ((val82[3]-val0)*val1);
          acc3 = (acc3+(alu117*(float)(((((alu117*val2)+val3)!=val18[0])!=1))*alu49*val58[0])+(alu118*(float)(((((alu118*val2)+val3)!=val18[0])!=1))*alu49*val58[0])+(alu119*(float)(((((alu119*val2)+val3)!=val18[1])!=1))*alu50*val58[1])+(alu120*(float)(((((alu120*val2)+val3)!=val18[1])!=1))*alu50*val58[1])+(alu121*(float)(((((alu121*val2)+val3)!=val19[0])!=1))*alu51*val59[0])+(alu122*(float)(((((alu122*val2)+val3)!=val19[0])!=1))*alu51*val59[0])+(alu123*(float)(((((alu123*val2)+val3)!=val19[1])!=1))*alu52*val59[1])+(alu124*(float)(((((alu124*val2)+val3)!=val19[1])!=1))*alu52*val59[1])+(alu125*(float)(((((alu125*val2)+val3)!=val20[0])!=1))*alu53*val60[0])+(alu126*(float)(((((alu126*val2)+val3)!=val20[0])!=1))*alu53*val60[0])+(alu127*(float)(((((alu127*val2)+val3)!=val20[1])!=1))*alu54*val60[1])+(alu128*(float)(((((alu128*val2)+val3)!=val20[1])!=1))*alu54*val60[1])+(alu129*(float)(((((alu129*val2)+val3)!=val21[0])!=1))*alu55*val61[0])+(alu130*(float)(((((alu130*val2)+val3)!=val21[0])!=1))*alu55*val61[0])+(alu131*(float)(((((alu131*val2)+val3)!=val21[1])!=1))*alu56*val61[1])+(alu132*(float)(((((alu132*val2)+val3)!=val21[1])!=1))*alu56*val61[1])+(alu133*(float)(((((alu133*val2)+val3)!=val22[0])!=1))*alu57*val62[0])+(alu134*(float)(((((alu134*val2)+val3)!=val22[0])!=1))*alu57*val62[0])+(alu135*(float)(((((alu135*val2)+val3)!=val22[1])!=1))*alu58*val62[1])+(alu136*(float)(((((alu136*val2)+val3)!=val22[1])!=1))*alu58*val62[1]));
          float4 val83 = *((float4*)(data1+alu0));
          float alu137 = ((val83[0]-val0)*val1);
          float alu138 = ((val83[1]-val0)*val1);
          float alu139 = ((val83[2]-val0)*val1);
          float alu140 = ((val83[3]-val0)*val1);
          acc0 = (acc0+(alu137*(float)(((((alu137*val2)+val3)!=val23[0])!=1))*alu59*val63[0])+(alu138*(float)(((((alu138*val2)+val3)!=val23[0])!=1))*alu59*val63[0])+(alu139*(float)(((((alu139*val2)+val3)!=val23[1])!=1))*alu60*val63[1])+(alu140*(float)(((((alu140*val2)+val3)!=val23[1])!=1))*alu60*val63[1])+(alu61*(float)(((((alu61*val2)+val3)!=val4[0])!=1))*alu21*val44[0])+(alu62*(float)(((((alu62*val2)+val3)!=val4[0])!=1))*alu21*val44[0])+(alu63*(float)(((((alu63*val2)+val3)!=val4[1])!=1))*alu22*val44[1])+(alu64*(float)(((((alu64*val2)+val3)!=val4[1])!=1))*alu22*val44[1])+(alu65*(float)(((((alu65*val2)+val3)!=val5[0])!=1))*alu23*val45[0])+(alu66*(float)(((((alu66*val2)+val3)!=val5[0])!=1))*alu23*val45[0])+(alu67*(float)(((((alu67*val2)+val3)!=val5[1])!=1))*alu24*val45[1])+(alu68*(float)(((((alu68*val2)+val3)!=val5[1])!=1))*alu24*val45[1])+(alu69*(float)(((((alu69*val2)+val3)!=val6[0])!=1))*alu25*val46[0])+(alu70*(float)(((((alu70*val2)+val3)!=val6[0])!=1))*alu25*val46[0])+(alu71*(float)(((((alu71*val2)+val3)!=val6[1])!=1))*alu26*val46[1])+(alu72*(float)(((((alu72*val2)+val3)!=val6[1])!=1))*alu26*val46[1])+(alu73*(float)(((((alu73*val2)+val3)!=val7[0])!=1))*alu27*val47[0])+(alu74*(float)(((((alu74*val2)+val3)!=val7[0])!=1))*alu27*val47[0])+(alu75*(float)(((((alu75*val2)+val3)!=val7[1])!=1))*alu28*val47[1])+(alu76*(float)(((((alu76*val2)+val3)!=val7[1])!=1))*alu28*val47[1]));
        }
      }
      *((float4*)(data0+(ridx0<<8)+(ridx1<<2))) = (float4){acc0,acc1,acc2,acc3};
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_64_2_20_4_20n5(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float val0 = *(data1+ridx0);
    float val1 = *(data2+ridx0);
    float val2 = *(data4+ridx0);
    float val3 = *(data5+ridx0);
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float acc0 = 0.0f;
      float acc1 = 0.0f;
      float acc2 = 0.0f;
      float acc3 = 0.0f;
      for (int ridx2 = 0; ridx2 < 2; ridx2++) {
        for (int ridx3 = 0; ridx3 < 20; ridx3++) {
          int alu0 = ((ridx0*400)+(ridx1*102400)+(ridx2*12800)+(ridx3*20));
          int alu1 = ((ridx0*100)+(ridx1*25600)+(ridx2*3200)+((ridx3>>1)*10));
          int alu2 = (alu1+2);
          int alu3 = (alu1+4);
          int alu4 = (alu1+6);
          int alu5 = (alu1+8);
          int alu6 = (alu1+6400);
          int alu7 = (alu1+6402);
          int alu8 = (alu1+6404);
          int alu9 = (alu1+6406);
          int alu10 = (alu1+6408);
          int alu11 = (alu1+12800);
          int alu12 = (alu1+12802);
          int alu13 = (alu1+12804);
          int alu14 = (alu1+12806);
          int alu15 = (alu1+12808);
          int alu16 = (alu1+19200);
          int alu17 = (alu1+19202);
          int alu18 = (alu1+19204);
          int alu19 = (alu1+19206);
          int alu20 = (alu1+19208);
          float2 val4 = *((float2*)(data6+alu2));
          float2 val5 = *((float2*)(data6+alu3));
          float2 val6 = *((float2*)(data6+alu4));
          float2 val7 = *((float2*)(data6+alu5));
          float2 val8 = *((float2*)(data6+alu6));
          float2 val9 = *((float2*)(data6+alu7));
          float2 val10 = *((float2*)(data6+alu8));
          float2 val11 = *((float2*)(data6+alu9));
          float2 val12 = *((float2*)(data6+alu10));
          float2 val13 = *((float2*)(data6+alu11));
          float2 val14 = *((float2*)(data6+alu12));
          float2 val15 = *((float2*)(data6+alu13));
          float2 val16 = *((float2*)(data6+alu14));
          float2 val17 = *((float2*)(data6+alu15));
          float2 val18 = *((float2*)(data6+alu16));
          float2 val19 = *((float2*)(data6+alu17));
          float2 val20 = *((float2*)(data6+alu18));
          float2 val21 = *((float2*)(data6+alu19));
          float2 val22 = *((float2*)(data6+alu20));
          float2 val23 = *((float2*)(data6+alu1));
          float2 val24 = *((float2*)(data7+alu2));
          float alu21 = (1/val24[0]);
          float alu22 = (1/val24[1]);
          float2 val25 = *((float2*)(data7+alu3));
          float alu23 = (1/val25[0]);
          float alu24 = (1/val25[1]);
          float2 val26 = *((float2*)(data7+alu4));
          float alu25 = (1/val26[0]);
          float alu26 = (1/val26[1]);
          float2 val27 = *((float2*)(data7+alu5));
          float alu27 = (1/val27[0]);
          float alu28 = (1/val27[1]);
          float2 val28 = *((float2*)(data7+alu6));
          float alu29 = (1/val28[0]);
          float alu30 = (1/val28[1]);
          float2 val29 = *((float2*)(data7+alu7));
          float alu31 = (1/val29[0]);
          float alu32 = (1/val29[1]);
          float2 val30 = *((float2*)(data7+alu8));
          float alu33 = (1/val30[0]);
          float alu34 = (1/val30[1]);
          float2 val31 = *((float2*)(data7+alu9));
          float alu35 = (1/val31[0]);
          float alu36 = (1/val31[1]);
          float2 val32 = *((float2*)(data7+alu10));
          float alu37 = (1/val32[0]);
          float alu38 = (1/val32[1]);
          float2 val33 = *((float2*)(data7+alu11));
          float alu39 = (1/val33[0]);
          float alu40 = (1/val33[1]);
          float2 val34 = *((float2*)(data7+alu12));
          float alu41 = (1/val34[0]);
          float alu42 = (1/val34[1]);
          float2 val35 = *((float2*)(data7+alu13));
          float alu43 = (1/val35[0]);
          float alu44 = (1/val35[1]);
          float2 val36 = *((float2*)(data7+alu14));
          float alu45 = (1/val36[0]);
          float alu46 = (1/val36[1]);
          float2 val37 = *((float2*)(data7+alu15));
          float alu47 = (1/val37[0]);
          float alu48 = (1/val37[1]);
          float2 val38 = *((float2*)(data7+alu16));
          float alu49 = (1/val38[0]);
          float alu50 = (1/val38[1]);
          float2 val39 = *((float2*)(data7+alu17));
          float alu51 = (1/val39[0]);
          float alu52 = (1/val39[1]);
          float2 val40 = *((float2*)(data7+alu18));
          float alu53 = (1/val40[0]);
          float alu54 = (1/val40[1]);
          float2 val41 = *((float2*)(data7+alu19));
          float alu55 = (1/val41[0]);
          float alu56 = (1/val41[1]);
          float2 val42 = *((float2*)(data7+alu20));
          float alu57 = (1/val42[0]);
          float alu58 = (1/val42[1]);
          float2 val43 = *((float2*)(data7+alu1));
          float alu59 = (1/val43[0]);
          float alu60 = (1/val43[1]);
          float2 val44 = *((float2*)(data8+alu2));
          float2 val45 = *((float2*)(data8+alu3));
          float2 val46 = *((float2*)(data8+alu4));
          float2 val47 = *((float2*)(data8+alu5));
          float2 val48 = *((float2*)(data8+alu6));
          float2 val49 = *((float2*)(data8+alu7));
          float2 val50 = *((float2*)(data8+alu8));
          float2 val51 = *((float2*)(data8+alu9));
          float2 val52 = *((float2*)(data8+alu10));
          float2 val53 = *((float2*)(data8+alu11));
          float2 val54 = *((float2*)(data8+alu12));
          float2 val55 = *((float2*)(data8+alu13));
          float2 val56 = *((float2*)(data8+alu14));
          float2 val57 = *((float2*)(data8+alu15));
          float2 val58 = *((float2*)(data8+alu16));
          float2 val59 = *((float2*)(data8+alu17));
          float2 val60 = *((float2*)(data8+alu18));
          float2 val61 = *((float2*)(data8+alu19));
          float2 val62 = *((float2*)(data8+alu20));
          float2 val63 = *((float2*)(data8+alu1));
          float4 val64 = *((float4*)(data3+alu0+4));
          float4 val65 = *((float4*)(data3+alu0+8));
          float4 val66 = *((float4*)(data3+alu0+12));
          float4 val67 = *((float4*)(data3+alu0+16));
          float4 val68 = *((float4*)(data3+alu0+25600));
          float4 val69 = *((float4*)(data3+alu0+25604));
          float4 val70 = *((float4*)(data3+alu0+25608));
          float4 val71 = *((float4*)(data3+alu0+25612));
          float4 val72 = *((float4*)(data3+alu0+25616));
          acc1 = (acc1+(((((((((((((((((((-(val0*val1*(float)((((((val68[0]-val2)*val0*val1)+val3)!=val8[0])!=1))*alu29*val48[0])-(val0*val1*(float)((((((val68[1]-val2)*val0*val1)+val3)!=val8[0])!=1))*alu29*val48[0]))-(val0*val1*(float)((((((val68[2]-val2)*val0*val1)+val3)!=val8[1])!=1))*alu30*val48[1]))-(val0*val1*(float)((((((val68[3]-val2)*val0*val1)+val3)!=val8[1])!=1))*alu30*val48[1]))-(val0*val1*(float)((((((val69[0]-val2)*val0*val1)+val3)!=val9[0])!=1))*alu31*val49[0]))-(val0*val1*(float)((((((val69[1]-val2)*val0*val1)+val3)!=val9[0])!=1))*alu31*val49[0]))-(val0*val1*(float)((((((val69[2]-val2)*val0*val1)+val3)!=val9[1])!=1))*alu32*val49[1]))-(val0*val1*(float)((((((val69[3]-val2)*val0*val1)+val3)!=val9[1])!=1))*alu32*val49[1]))-(val0*val1*(float)((((((val70[0]-val2)*val0*val1)+val3)!=val10[0])!=1))*alu33*val50[0]))-(val0*val1*(float)((((((val70[1]-val2)*val0*val1)+val3)!=val10[0])!=1))*alu33*val50[0]))-(val0*val1*(float)((((((val70[2]-val2)*val0*val1)+val3)!=val10[1])!=1))*alu34*val50[1]))-(val0*val1*(float)((((((val70[3]-val2)*val0*val1)+val3)!=val10[1])!=1))*alu34*val50[1]))-(val0*val1*(float)((((((val71[0]-val2)*val0*val1)+val3)!=val11[0])!=1))*alu35*val51[0]))-(val0*val1*(float)((((((val71[1]-val2)*val0*val1)+val3)!=val11[0])!=1))*alu35*val51[0]))-(val0*val1*(float)((((((val71[2]-val2)*val0*val1)+val3)!=val11[1])!=1))*alu36*val51[1]))-(val0*val1*(float)((((((val71[3]-val2)*val0*val1)+val3)!=val11[1])!=1))*alu36*val51[1]))-(val0*val1*(float)((((((val72[0]-val2)*val0*val1)+val3)!=val12[0])!=1))*alu37*val52[0]))-(val0*val1*(float)((((((val72[1]-val2)*val0*val1)+val3)!=val12[0])!=1))*alu37*val52[0]))-(val0*val1*(float)((((((val72[2]-val2)*val0*val1)+val3)!=val12[1])!=1))*alu38*val52[1]))-(val0*val1*(float)((((((val72[3]-val2)*val0*val1)+val3)!=val12[1])!=1))*alu38*val52[1])));
          float4 val73 = *((float4*)(data3+alu0+51200));
          float4 val74 = *((float4*)(data3+alu0+51204));
          float4 val75 = *((float4*)(data3+alu0+51208));
          float4 val76 = *((float4*)(data3+alu0+51212));
          float4 val77 = *((float4*)(data3+alu0+51216));
          acc2 = (acc2+(((((((((((((((((((-(val0*val1*(float)((((((val73[0]-val2)*val0*val1)+val3)!=val13[0])!=1))*alu39*val53[0])-(val0*val1*(float)((((((val73[1]-val2)*val0*val1)+val3)!=val13[0])!=1))*alu39*val53[0]))-(val0*val1*(float)((((((val73[2]-val2)*val0*val1)+val3)!=val13[1])!=1))*alu40*val53[1]))-(val0*val1*(float)((((((val73[3]-val2)*val0*val1)+val3)!=val13[1])!=1))*alu40*val53[1]))-(val0*val1*(float)((((((val74[0]-val2)*val0*val1)+val3)!=val14[0])!=1))*alu41*val54[0]))-(val0*val1*(float)((((((val74[1]-val2)*val0*val1)+val3)!=val14[0])!=1))*alu41*val54[0]))-(val0*val1*(float)((((((val74[2]-val2)*val0*val1)+val3)!=val14[1])!=1))*alu42*val54[1]))-(val0*val1*(float)((((((val74[3]-val2)*val0*val1)+val3)!=val14[1])!=1))*alu42*val54[1]))-(val0*val1*(float)((((((val75[0]-val2)*val0*val1)+val3)!=val15[0])!=1))*alu43*val55[0]))-(val0*val1*(float)((((((val75[1]-val2)*val0*val1)+val3)!=val15[0])!=1))*alu43*val55[0]))-(val0*val1*(float)((((((val75[2]-val2)*val0*val1)+val3)!=val15[1])!=1))*alu44*val55[1]))-(val0*val1*(float)((((((val75[3]-val2)*val0*val1)+val3)!=val15[1])!=1))*alu44*val55[1]))-(val0*val1*(float)((((((val76[0]-val2)*val0*val1)+val3)!=val16[0])!=1))*alu45*val56[0]))-(val0*val1*(float)((((((val76[1]-val2)*val0*val1)+val3)!=val16[0])!=1))*alu45*val56[0]))-(val0*val1*(float)((((((val76[2]-val2)*val0*val1)+val3)!=val16[1])!=1))*alu46*val56[1]))-(val0*val1*(float)((((((val76[3]-val2)*val0*val1)+val3)!=val16[1])!=1))*alu46*val56[1]))-(val0*val1*(float)((((((val77[0]-val2)*val0*val1)+val3)!=val17[0])!=1))*alu47*val57[0]))-(val0*val1*(float)((((((val77[1]-val2)*val0*val1)+val3)!=val17[0])!=1))*alu47*val57[0]))-(val0*val1*(float)((((((val77[2]-val2)*val0*val1)+val3)!=val17[1])!=1))*alu48*val57[1]))-(val0*val1*(float)((((((val77[3]-val2)*val0*val1)+val3)!=val17[1])!=1))*alu48*val57[1])));
          float4 val78 = *((float4*)(data3+alu0+76800));
          float4 val79 = *((float4*)(data3+alu0+76804));
          float4 val80 = *((float4*)(data3+alu0+76808));
          float4 val81 = *((float4*)(data3+alu0+76812));
          float4 val82 = *((float4*)(data3+alu0+76816));
          acc3 = (acc3+(((((((((((((((((((-(val0*val1*(float)((((((val78[0]-val2)*val0*val1)+val3)!=val18[0])!=1))*alu49*val58[0])-(val0*val1*(float)((((((val78[1]-val2)*val0*val1)+val3)!=val18[0])!=1))*alu49*val58[0]))-(val0*val1*(float)((((((val78[2]-val2)*val0*val1)+val3)!=val18[1])!=1))*alu50*val58[1]))-(val0*val1*(float)((((((val78[3]-val2)*val0*val1)+val3)!=val18[1])!=1))*alu50*val58[1]))-(val0*val1*(float)((((((val79[0]-val2)*val0*val1)+val3)!=val19[0])!=1))*alu51*val59[0]))-(val0*val1*(float)((((((val79[1]-val2)*val0*val1)+val3)!=val19[0])!=1))*alu51*val59[0]))-(val0*val1*(float)((((((val79[2]-val2)*val0*val1)+val3)!=val19[1])!=1))*alu52*val59[1]))-(val0*val1*(float)((((((val79[3]-val2)*val0*val1)+val3)!=val19[1])!=1))*alu52*val59[1]))-(val0*val1*(float)((((((val80[0]-val2)*val0*val1)+val3)!=val20[0])!=1))*alu53*val60[0]))-(val0*val1*(float)((((((val80[1]-val2)*val0*val1)+val3)!=val20[0])!=1))*alu53*val60[0]))-(val0*val1*(float)((((((val80[2]-val2)*val0*val1)+val3)!=val20[1])!=1))*alu54*val60[1]))-(val0*val1*(float)((((((val80[3]-val2)*val0*val1)+val3)!=val20[1])!=1))*alu54*val60[1]))-(val0*val1*(float)((((((val81[0]-val2)*val0*val1)+val3)!=val21[0])!=1))*alu55*val61[0]))-(val0*val1*(float)((((((val81[1]-val2)*val0*val1)+val3)!=val21[0])!=1))*alu55*val61[0]))-(val0*val1*(float)((((((val81[2]-val2)*val0*val1)+val3)!=val21[1])!=1))*alu56*val61[1]))-(val0*val1*(float)((((((val81[3]-val2)*val0*val1)+val3)!=val21[1])!=1))*alu56*val61[1]))-(val0*val1*(float)((((((val82[0]-val2)*val0*val1)+val3)!=val22[0])!=1))*alu57*val62[0]))-(val0*val1*(float)((((((val82[1]-val2)*val0*val1)+val3)!=val22[0])!=1))*alu57*val62[0]))-(val0*val1*(float)((((((val82[2]-val2)*val0*val1)+val3)!=val22[1])!=1))*alu58*val62[1]))-(val0*val1*(float)((((((val82[3]-val2)*val0*val1)+val3)!=val22[1])!=1))*alu58*val62[1])));
          float4 val83 = *((float4*)(data3+alu0));
          acc0 = (acc0+(((((((((((((((((((-(val0*val1*(float)((((((val83[0]-val2)*val0*val1)+val3)!=val23[0])!=1))*alu59*val63[0])-(val0*val1*(float)((((((val83[1]-val2)*val0*val1)+val3)!=val23[0])!=1))*alu59*val63[0]))-(val0*val1*(float)((((((val83[2]-val2)*val0*val1)+val3)!=val23[1])!=1))*alu60*val63[1]))-(val0*val1*(float)((((((val83[3]-val2)*val0*val1)+val3)!=val23[1])!=1))*alu60*val63[1]))-(val0*val1*(float)((((((val64[0]-val2)*val0*val1)+val3)!=val4[0])!=1))*alu21*val44[0]))-(val0*val1*(float)((((((val64[1]-val2)*val0*val1)+val3)!=val4[0])!=1))*alu21*val44[0]))-(val0*val1*(float)((((((val64[2]-val2)*val0*val1)+val3)!=val4[1])!=1))*alu22*val44[1]))-(val0*val1*(float)((((((val64[3]-val2)*val0*val1)+val3)!=val4[1])!=1))*alu22*val44[1]))-(val0*val1*(float)((((((val65[0]-val2)*val0*val1)+val3)!=val5[0])!=1))*alu23*val45[0]))-(val0*val1*(float)((((((val65[1]-val2)*val0*val1)+val3)!=val5[0])!=1))*alu23*val45[0]))-(val0*val1*(float)((((((val65[2]-val2)*val0*val1)+val3)!=val5[1])!=1))*alu24*val45[1]))-(val0*val1*(float)((((((val65[3]-val2)*val0*val1)+val3)!=val5[1])!=1))*alu24*val45[1]))-(val0*val1*(float)((((((val66[0]-val2)*val0*val1)+val3)!=val6[0])!=1))*alu25*val46[0]))-(val0*val1*(float)((((((val66[1]-val2)*val0*val1)+val3)!=val6[0])!=1))*alu25*val46[0]))-(val0*val1*(float)((((((val66[2]-val2)*val0*val1)+val3)!=val6[1])!=1))*alu26*val46[1]))-(val0*val1*(float)((((((val66[3]-val2)*val0*val1)+val3)!=val6[1])!=1))*alu26*val46[1]))-(val0*val1*(float)((((((val67[0]-val2)*val0*val1)+val3)!=val7[0])!=1))*alu27*val47[0]))-(val0*val1*(float)((((((val67[1]-val2)*val0*val1)+val3)!=val7[0])!=1))*alu27*val47[0]))-(val0*val1*(float)((((((val67[2]-val2)*val0*val1)+val3)!=val7[1])!=1))*alu28*val47[1]))-(val0*val1*(float)((((((val67[3]-val2)*val0*val1)+val3)!=val7[1])!=1))*alu28*val47[1])));
        }
      }
      *((float4*)(data0+(ridx0<<8)+(ridx1<<2))) = (float4){acc0,acc1,acc2,acc3};
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_64_2_20_4_20n6(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float val0 = *(data2+ridx0);
    float val1 = *(data3+ridx0);
    float val2 = *(data4+ridx0);
    float val3 = *(data5+ridx0);
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float acc0 = 0.0f;
      float acc1 = 0.0f;
      float acc2 = 0.0f;
      float acc3 = 0.0f;
      for (int ridx2 = 0; ridx2 < 2; ridx2++) {
        for (int ridx3 = 0; ridx3 < 20; ridx3++) {
          int alu0 = ((ridx0*400)+(ridx1*102400)+(ridx2*12800)+(ridx3*20));
          int alu1 = ((ridx0*100)+(ridx1*25600)+(ridx2*3200)+((ridx3>>1)*10));
          int alu2 = (alu1+2);
          int alu3 = (alu1+4);
          int alu4 = (alu1+6);
          int alu5 = (alu1+8);
          int alu6 = (alu1+6400);
          int alu7 = (alu1+6402);
          int alu8 = (alu1+6404);
          int alu9 = (alu1+6406);
          int alu10 = (alu1+6408);
          int alu11 = (alu1+12800);
          int alu12 = (alu1+12802);
          int alu13 = (alu1+12804);
          int alu14 = (alu1+12806);
          int alu15 = (alu1+12808);
          int alu16 = (alu1+19200);
          int alu17 = (alu1+19202);
          int alu18 = (alu1+19204);
          int alu19 = (alu1+19206);
          int alu20 = (alu1+19208);
          float2 val4 = *((float2*)(data6+alu2));
          float2 val5 = *((float2*)(data6+alu3));
          float2 val6 = *((float2*)(data6+alu4));
          float2 val7 = *((float2*)(data6+alu5));
          float2 val8 = *((float2*)(data6+alu6));
          float2 val9 = *((float2*)(data6+alu7));
          float2 val10 = *((float2*)(data6+alu8));
          float2 val11 = *((float2*)(data6+alu9));
          float2 val12 = *((float2*)(data6+alu10));
          float2 val13 = *((float2*)(data6+alu11));
          float2 val14 = *((float2*)(data6+alu12));
          float2 val15 = *((float2*)(data6+alu13));
          float2 val16 = *((float2*)(data6+alu14));
          float2 val17 = *((float2*)(data6+alu15));
          float2 val18 = *((float2*)(data6+alu16));
          float2 val19 = *((float2*)(data6+alu17));
          float2 val20 = *((float2*)(data6+alu18));
          float2 val21 = *((float2*)(data6+alu19));
          float2 val22 = *((float2*)(data6+alu20));
          float2 val23 = *((float2*)(data6+alu1));
          float2 val24 = *((float2*)(data7+alu2));
          float alu21 = (1/val24[0]);
          float alu22 = (1/val24[1]);
          float2 val25 = *((float2*)(data7+alu3));
          float alu23 = (1/val25[0]);
          float alu24 = (1/val25[1]);
          float2 val26 = *((float2*)(data7+alu4));
          float alu25 = (1/val26[0]);
          float alu26 = (1/val26[1]);
          float2 val27 = *((float2*)(data7+alu5));
          float alu27 = (1/val27[0]);
          float alu28 = (1/val27[1]);
          float2 val28 = *((float2*)(data7+alu6));
          float alu29 = (1/val28[0]);
          float alu30 = (1/val28[1]);
          float2 val29 = *((float2*)(data7+alu7));
          float alu31 = (1/val29[0]);
          float alu32 = (1/val29[1]);
          float2 val30 = *((float2*)(data7+alu8));
          float alu33 = (1/val30[0]);
          float alu34 = (1/val30[1]);
          float2 val31 = *((float2*)(data7+alu9));
          float alu35 = (1/val31[0]);
          float alu36 = (1/val31[1]);
          float2 val32 = *((float2*)(data7+alu10));
          float alu37 = (1/val32[0]);
          float alu38 = (1/val32[1]);
          float2 val33 = *((float2*)(data7+alu11));
          float alu39 = (1/val33[0]);
          float alu40 = (1/val33[1]);
          float2 val34 = *((float2*)(data7+alu12));
          float alu41 = (1/val34[0]);
          float alu42 = (1/val34[1]);
          float2 val35 = *((float2*)(data7+alu13));
          float alu43 = (1/val35[0]);
          float alu44 = (1/val35[1]);
          float2 val36 = *((float2*)(data7+alu14));
          float alu45 = (1/val36[0]);
          float alu46 = (1/val36[1]);
          float2 val37 = *((float2*)(data7+alu15));
          float alu47 = (1/val37[0]);
          float alu48 = (1/val37[1]);
          float2 val38 = *((float2*)(data7+alu16));
          float alu49 = (1/val38[0]);
          float alu50 = (1/val38[1]);
          float2 val39 = *((float2*)(data7+alu17));
          float alu51 = (1/val39[0]);
          float alu52 = (1/val39[1]);
          float2 val40 = *((float2*)(data7+alu18));
          float alu53 = (1/val40[0]);
          float alu54 = (1/val40[1]);
          float2 val41 = *((float2*)(data7+alu19));
          float alu55 = (1/val41[0]);
          float alu56 = (1/val41[1]);
          float2 val42 = *((float2*)(data7+alu20));
          float alu57 = (1/val42[0]);
          float alu58 = (1/val42[1]);
          float2 val43 = *((float2*)(data7+alu1));
          float alu59 = (1/val43[0]);
          float alu60 = (1/val43[1]);
          float2 val44 = *((float2*)(data8+alu2));
          float2 val45 = *((float2*)(data8+alu3));
          float2 val46 = *((float2*)(data8+alu4));
          float2 val47 = *((float2*)(data8+alu5));
          float2 val48 = *((float2*)(data8+alu6));
          float2 val49 = *((float2*)(data8+alu7));
          float2 val50 = *((float2*)(data8+alu8));
          float2 val51 = *((float2*)(data8+alu9));
          float2 val52 = *((float2*)(data8+alu10));
          float2 val53 = *((float2*)(data8+alu11));
          float2 val54 = *((float2*)(data8+alu12));
          float2 val55 = *((float2*)(data8+alu13));
          float2 val56 = *((float2*)(data8+alu14));
          float2 val57 = *((float2*)(data8+alu15));
          float2 val58 = *((float2*)(data8+alu16));
          float2 val59 = *((float2*)(data8+alu17));
          float2 val60 = *((float2*)(data8+alu18));
          float2 val61 = *((float2*)(data8+alu19));
          float2 val62 = *((float2*)(data8+alu20));
          float2 val63 = *((float2*)(data8+alu1));
          float4 val64 = *((float4*)(data1+alu0+4));
          float alu61 = (val64[0]-val0);
          float alu62 = (val64[1]-val0);
          float alu63 = (val64[2]-val0);
          float alu64 = (val64[3]-val0);
          float4 val65 = *((float4*)(data1+alu0+8));
          float alu65 = (val65[0]-val0);
          float alu66 = (val65[1]-val0);
          float alu67 = (val65[2]-val0);
          float alu68 = (val65[3]-val0);
          float4 val66 = *((float4*)(data1+alu0+12));
          float alu69 = (val66[0]-val0);
          float alu70 = (val66[1]-val0);
          float alu71 = (val66[2]-val0);
          float alu72 = (val66[3]-val0);
          float4 val67 = *((float4*)(data1+alu0+16));
          float alu73 = (val67[0]-val0);
          float alu74 = (val67[1]-val0);
          float alu75 = (val67[2]-val0);
          float alu76 = (val67[3]-val0);
          float4 val68 = *((float4*)(data1+alu0+25600));
          float alu77 = (val68[0]-val0);
          float alu78 = (val68[1]-val0);
          float alu79 = (val68[2]-val0);
          float alu80 = (val68[3]-val0);
          float4 val69 = *((float4*)(data1+alu0+25604));
          float alu81 = (val69[0]-val0);
          float alu82 = (val69[1]-val0);
          float alu83 = (val69[2]-val0);
          float alu84 = (val69[3]-val0);
          float4 val70 = *((float4*)(data1+alu0+25608));
          float alu85 = (val70[0]-val0);
          float alu86 = (val70[1]-val0);
          float alu87 = (val70[2]-val0);
          float alu88 = (val70[3]-val0);
          float4 val71 = *((float4*)(data1+alu0+25612));
          float alu89 = (val71[0]-val0);
          float alu90 = (val71[1]-val0);
          float alu91 = (val71[2]-val0);
          float alu92 = (val71[3]-val0);
          float4 val72 = *((float4*)(data1+alu0+25616));
          float alu93 = (val72[0]-val0);
          float alu94 = (val72[1]-val0);
          float alu95 = (val72[2]-val0);
          float alu96 = (val72[3]-val0);
          acc1 = (acc1+(alu77*val1*(float)(((((alu77*val2*val1)+val3)!=val8[0])!=1))*alu29*val48[0])+(alu78*val1*(float)(((((alu78*val2*val1)+val3)!=val8[0])!=1))*alu29*val48[0])+(alu79*val1*(float)(((((alu79*val2*val1)+val3)!=val8[1])!=1))*alu30*val48[1])+(alu80*val1*(float)(((((alu80*val2*val1)+val3)!=val8[1])!=1))*alu30*val48[1])+(alu81*val1*(float)(((((alu81*val2*val1)+val3)!=val9[0])!=1))*alu31*val49[0])+(alu82*val1*(float)(((((alu82*val2*val1)+val3)!=val9[0])!=1))*alu31*val49[0])+(alu83*val1*(float)(((((alu83*val2*val1)+val3)!=val9[1])!=1))*alu32*val49[1])+(alu84*val1*(float)(((((alu84*val2*val1)+val3)!=val9[1])!=1))*alu32*val49[1])+(alu85*val1*(float)(((((alu85*val2*val1)+val3)!=val10[0])!=1))*alu33*val50[0])+(alu86*val1*(float)(((((alu86*val2*val1)+val3)!=val10[0])!=1))*alu33*val50[0])+(alu87*val1*(float)(((((alu87*val2*val1)+val3)!=val10[1])!=1))*alu34*val50[1])+(alu88*val1*(float)(((((alu88*val2*val1)+val3)!=val10[1])!=1))*alu34*val50[1])+(alu89*val1*(float)(((((alu89*val2*val1)+val3)!=val11[0])!=1))*alu35*val51[0])+(alu90*val1*(float)(((((alu90*val2*val1)+val3)!=val11[0])!=1))*alu35*val51[0])+(alu91*val1*(float)(((((alu91*val2*val1)+val3)!=val11[1])!=1))*alu36*val51[1])+(alu92*val1*(float)(((((alu92*val2*val1)+val3)!=val11[1])!=1))*alu36*val51[1])+(alu93*val1*(float)(((((alu93*val2*val1)+val3)!=val12[0])!=1))*alu37*val52[0])+(alu94*val1*(float)(((((alu94*val2*val1)+val3)!=val12[0])!=1))*alu37*val52[0])+(alu95*val1*(float)(((((alu95*val2*val1)+val3)!=val12[1])!=1))*alu38*val52[1])+(alu96*val1*(float)(((((alu96*val2*val1)+val3)!=val12[1])!=1))*alu38*val52[1]));
          float4 val73 = *((float4*)(data1+alu0+51200));
          float alu97 = (val73[0]-val0);
          float alu98 = (val73[1]-val0);
          float alu99 = (val73[2]-val0);
          float alu100 = (val73[3]-val0);
          float4 val74 = *((float4*)(data1+alu0+51204));
          float alu101 = (val74[0]-val0);
          float alu102 = (val74[1]-val0);
          float alu103 = (val74[2]-val0);
          float alu104 = (val74[3]-val0);
          float4 val75 = *((float4*)(data1+alu0+51208));
          float alu105 = (val75[0]-val0);
          float alu106 = (val75[1]-val0);
          float alu107 = (val75[2]-val0);
          float alu108 = (val75[3]-val0);
          float4 val76 = *((float4*)(data1+alu0+51212));
          float alu109 = (val76[0]-val0);
          float alu110 = (val76[1]-val0);
          float alu111 = (val76[2]-val0);
          float alu112 = (val76[3]-val0);
          float4 val77 = *((float4*)(data1+alu0+51216));
          float alu113 = (val77[0]-val0);
          float alu114 = (val77[1]-val0);
          float alu115 = (val77[2]-val0);
          float alu116 = (val77[3]-val0);
          acc2 = (acc2+(alu97*val1*(float)(((((alu97*val2*val1)+val3)!=val13[0])!=1))*alu39*val53[0])+(alu98*val1*(float)(((((alu98*val2*val1)+val3)!=val13[0])!=1))*alu39*val53[0])+(alu99*val1*(float)(((((alu99*val2*val1)+val3)!=val13[1])!=1))*alu40*val53[1])+(alu100*val1*(float)(((((alu100*val2*val1)+val3)!=val13[1])!=1))*alu40*val53[1])+(alu101*val1*(float)(((((alu101*val2*val1)+val3)!=val14[0])!=1))*alu41*val54[0])+(alu102*val1*(float)(((((alu102*val2*val1)+val3)!=val14[0])!=1))*alu41*val54[0])+(alu103*val1*(float)(((((alu103*val2*val1)+val3)!=val14[1])!=1))*alu42*val54[1])+(alu104*val1*(float)(((((alu104*val2*val1)+val3)!=val14[1])!=1))*alu42*val54[1])+(alu105*val1*(float)(((((alu105*val2*val1)+val3)!=val15[0])!=1))*alu43*val55[0])+(alu106*val1*(float)(((((alu106*val2*val1)+val3)!=val15[0])!=1))*alu43*val55[0])+(alu107*val1*(float)(((((alu107*val2*val1)+val3)!=val15[1])!=1))*alu44*val55[1])+(alu108*val1*(float)(((((alu108*val2*val1)+val3)!=val15[1])!=1))*alu44*val55[1])+(alu109*val1*(float)(((((alu109*val2*val1)+val3)!=val16[0])!=1))*alu45*val56[0])+(alu110*val1*(float)(((((alu110*val2*val1)+val3)!=val16[0])!=1))*alu45*val56[0])+(alu111*val1*(float)(((((alu111*val2*val1)+val3)!=val16[1])!=1))*alu46*val56[1])+(alu112*val1*(float)(((((alu112*val2*val1)+val3)!=val16[1])!=1))*alu46*val56[1])+(alu113*val1*(float)(((((alu113*val2*val1)+val3)!=val17[0])!=1))*alu47*val57[0])+(alu114*val1*(float)(((((alu114*val2*val1)+val3)!=val17[0])!=1))*alu47*val57[0])+(alu115*val1*(float)(((((alu115*val2*val1)+val3)!=val17[1])!=1))*alu48*val57[1])+(alu116*val1*(float)(((((alu116*val2*val1)+val3)!=val17[1])!=1))*alu48*val57[1]));
          float4 val78 = *((float4*)(data1+alu0+76800));
          float alu117 = (val78[0]-val0);
          float alu118 = (val78[1]-val0);
          float alu119 = (val78[2]-val0);
          float alu120 = (val78[3]-val0);
          float4 val79 = *((float4*)(data1+alu0+76804));
          float alu121 = (val79[0]-val0);
          float alu122 = (val79[1]-val0);
          float alu123 = (val79[2]-val0);
          float alu124 = (val79[3]-val0);
          float4 val80 = *((float4*)(data1+alu0+76808));
          float alu125 = (val80[0]-val0);
          float alu126 = (val80[1]-val0);
          float alu127 = (val80[2]-val0);
          float alu128 = (val80[3]-val0);
          float4 val81 = *((float4*)(data1+alu0+76812));
          float alu129 = (val81[0]-val0);
          float alu130 = (val81[1]-val0);
          float alu131 = (val81[2]-val0);
          float alu132 = (val81[3]-val0);
          float4 val82 = *((float4*)(data1+alu0+76816));
          float alu133 = (val82[0]-val0);
          float alu134 = (val82[1]-val0);
          float alu135 = (val82[2]-val0);
          float alu136 = (val82[3]-val0);
          acc3 = (acc3+(alu117*val1*(float)(((((alu117*val2*val1)+val3)!=val18[0])!=1))*alu49*val58[0])+(alu118*val1*(float)(((((alu118*val2*val1)+val3)!=val18[0])!=1))*alu49*val58[0])+(alu119*val1*(float)(((((alu119*val2*val1)+val3)!=val18[1])!=1))*alu50*val58[1])+(alu120*val1*(float)(((((alu120*val2*val1)+val3)!=val18[1])!=1))*alu50*val58[1])+(alu121*val1*(float)(((((alu121*val2*val1)+val3)!=val19[0])!=1))*alu51*val59[0])+(alu122*val1*(float)(((((alu122*val2*val1)+val3)!=val19[0])!=1))*alu51*val59[0])+(alu123*val1*(float)(((((alu123*val2*val1)+val3)!=val19[1])!=1))*alu52*val59[1])+(alu124*val1*(float)(((((alu124*val2*val1)+val3)!=val19[1])!=1))*alu52*val59[1])+(alu125*val1*(float)(((((alu125*val2*val1)+val3)!=val20[0])!=1))*alu53*val60[0])+(alu126*val1*(float)(((((alu126*val2*val1)+val3)!=val20[0])!=1))*alu53*val60[0])+(alu127*val1*(float)(((((alu127*val2*val1)+val3)!=val20[1])!=1))*alu54*val60[1])+(alu128*val1*(float)(((((alu128*val2*val1)+val3)!=val20[1])!=1))*alu54*val60[1])+(alu129*val1*(float)(((((alu129*val2*val1)+val3)!=val21[0])!=1))*alu55*val61[0])+(alu130*val1*(float)(((((alu130*val2*val1)+val3)!=val21[0])!=1))*alu55*val61[0])+(alu131*val1*(float)(((((alu131*val2*val1)+val3)!=val21[1])!=1))*alu56*val61[1])+(alu132*val1*(float)(((((alu132*val2*val1)+val3)!=val21[1])!=1))*alu56*val61[1])+(alu133*val1*(float)(((((alu133*val2*val1)+val3)!=val22[0])!=1))*alu57*val62[0])+(alu134*val1*(float)(((((alu134*val2*val1)+val3)!=val22[0])!=1))*alu57*val62[0])+(alu135*val1*(float)(((((alu135*val2*val1)+val3)!=val22[1])!=1))*alu58*val62[1])+(alu136*val1*(float)(((((alu136*val2*val1)+val3)!=val22[1])!=1))*alu58*val62[1]));
          float4 val83 = *((float4*)(data1+alu0));
          float alu137 = (val83[0]-val0);
          float alu138 = (val83[1]-val0);
          float alu139 = (val83[2]-val0);
          float alu140 = (val83[3]-val0);
          acc0 = (acc0+(alu137*val1*(float)(((((alu137*val2*val1)+val3)!=val23[0])!=1))*alu59*val63[0])+(alu138*val1*(float)(((((alu138*val2*val1)+val3)!=val23[0])!=1))*alu59*val63[0])+(alu139*val1*(float)(((((alu139*val2*val1)+val3)!=val23[1])!=1))*alu60*val63[1])+(alu140*val1*(float)(((((alu140*val2*val1)+val3)!=val23[1])!=1))*alu60*val63[1])+(alu61*val1*(float)(((((alu61*val2*val1)+val3)!=val4[0])!=1))*alu21*val44[0])+(alu62*val1*(float)(((((alu62*val2*val1)+val3)!=val4[0])!=1))*alu21*val44[0])+(alu63*val1*(float)(((((alu63*val2*val1)+val3)!=val4[1])!=1))*alu22*val44[1])+(alu64*val1*(float)(((((alu64*val2*val1)+val3)!=val4[1])!=1))*alu22*val44[1])+(alu65*val1*(float)(((((alu65*val2*val1)+val3)!=val5[0])!=1))*alu23*val45[0])+(alu66*val1*(float)(((((alu66*val2*val1)+val3)!=val5[0])!=1))*alu23*val45[0])+(alu67*val1*(float)(((((alu67*val2*val1)+val3)!=val5[1])!=1))*alu24*val45[1])+(alu68*val1*(float)(((((alu68*val2*val1)+val3)!=val5[1])!=1))*alu24*val45[1])+(alu69*val1*(float)(((((alu69*val2*val1)+val3)!=val6[0])!=1))*alu25*val46[0])+(alu70*val1*(float)(((((alu70*val2*val1)+val3)!=val6[0])!=1))*alu25*val46[0])+(alu71*val1*(float)(((((alu71*val2*val1)+val3)!=val6[1])!=1))*alu26*val46[1])+(alu72*val1*(float)(((((alu72*val2*val1)+val3)!=val6[1])!=1))*alu26*val46[1])+(alu73*val1*(float)(((((alu73*val2*val1)+val3)!=val7[0])!=1))*alu27*val47[0])+(alu74*val1*(float)(((((alu74*val2*val1)+val3)!=val7[0])!=1))*alu27*val47[0])+(alu75*val1*(float)(((((alu75*val2*val1)+val3)!=val7[1])!=1))*alu28*val47[1])+(alu76*val1*(float)(((((alu76*val2*val1)+val3)!=val7[1])!=1))*alu28*val47[1]));
        }
      }
      *((float4*)(data0+(ridx0<<8)+(ridx1<<2))) = (float4){acc0,acc1,acc2,acc3};
    }
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_64_2_20_4_20n7(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float val0 = *(data2+ridx0);
    float val1 = *(data3+ridx0);
    float val2 = *(data4+ridx0);
    float val3 = *(data5+ridx0);
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float acc0 = 0.0f;
      float acc1 = 0.0f;
      float acc2 = 0.0f;
      float acc3 = 0.0f;
      for (int ridx2 = 0; ridx2 < 2; ridx2++) {
        for (int ridx3 = 0; ridx3 < 20; ridx3++) {
          int alu0 = ((ridx0*400)+(ridx1*102400)+(ridx2*12800)+(ridx3*20));
          int alu1 = ((ridx0*100)+(ridx1*25600)+(ridx2*3200)+((ridx3>>1)*10));
          int alu2 = (alu1+2);
          int alu3 = (alu1+4);
          int alu4 = (alu1+6);
          int alu5 = (alu1+8);
          int alu6 = (alu1+6400);
          int alu7 = (alu1+6402);
          int alu8 = (alu1+6404);
          int alu9 = (alu1+6406);
          int alu10 = (alu1+6408);
          int alu11 = (alu1+12800);
          int alu12 = (alu1+12802);
          int alu13 = (alu1+12804);
          int alu14 = (alu1+12806);
          int alu15 = (alu1+12808);
          int alu16 = (alu1+19200);
          int alu17 = (alu1+19202);
          int alu18 = (alu1+19204);
          int alu19 = (alu1+19206);
          int alu20 = (alu1+19208);
          float2 val4 = *((float2*)(data6+alu2));
          float2 val5 = *((float2*)(data6+alu3));
          float2 val6 = *((float2*)(data6+alu4));
          float2 val7 = *((float2*)(data6+alu5));
          float2 val8 = *((float2*)(data6+alu6));
          float2 val9 = *((float2*)(data6+alu7));
          float2 val10 = *((float2*)(data6+alu8));
          float2 val11 = *((float2*)(data6+alu9));
          float2 val12 = *((float2*)(data6+alu10));
          float2 val13 = *((float2*)(data6+alu11));
          float2 val14 = *((float2*)(data6+alu12));
          float2 val15 = *((float2*)(data6+alu13));
          float2 val16 = *((float2*)(data6+alu14));
          float2 val17 = *((float2*)(data6+alu15));
          float2 val18 = *((float2*)(data6+alu16));
          float2 val19 = *((float2*)(data6+alu17));
          float2 val20 = *((float2*)(data6+alu18));
          float2 val21 = *((float2*)(data6+alu19));
          float2 val22 = *((float2*)(data6+alu20));
          float2 val23 = *((float2*)(data6+alu1));
          float2 val24 = *((float2*)(data7+alu2));
          float alu21 = (1/val24[0]);
          float alu22 = (1/val24[1]);
          float2 val25 = *((float2*)(data7+alu3));
          float alu23 = (1/val25[0]);
          float alu24 = (1/val25[1]);
          float2 val26 = *((float2*)(data7+alu4));
          float alu25 = (1/val26[0]);
          float alu26 = (1/val26[1]);
          float2 val27 = *((float2*)(data7+alu5));
          float alu27 = (1/val27[0]);
          float alu28 = (1/val27[1]);
          float2 val28 = *((float2*)(data7+alu6));
          float alu29 = (1/val28[0]);
          float alu30 = (1/val28[1]);
          float2 val29 = *((float2*)(data7+alu7));
          float alu31 = (1/val29[0]);
          float alu32 = (1/val29[1]);
          float2 val30 = *((float2*)(data7+alu8));
          float alu33 = (1/val30[0]);
          float alu34 = (1/val30[1]);
          float2 val31 = *((float2*)(data7+alu9));
          float alu35 = (1/val31[0]);
          float alu36 = (1/val31[1]);
          float2 val32 = *((float2*)(data7+alu10));
          float alu37 = (1/val32[0]);
          float alu38 = (1/val32[1]);
          float2 val33 = *((float2*)(data7+alu11));
          float alu39 = (1/val33[0]);
          float alu40 = (1/val33[1]);
          float2 val34 = *((float2*)(data7+alu12));
          float alu41 = (1/val34[0]);
          float alu42 = (1/val34[1]);
          float2 val35 = *((float2*)(data7+alu13));
          float alu43 = (1/val35[0]);
          float alu44 = (1/val35[1]);
          float2 val36 = *((float2*)(data7+alu14));
          float alu45 = (1/val36[0]);
          float alu46 = (1/val36[1]);
          float2 val37 = *((float2*)(data7+alu15));
          float alu47 = (1/val37[0]);
          float alu48 = (1/val37[1]);
          float2 val38 = *((float2*)(data7+alu16));
          float alu49 = (1/val38[0]);
          float alu50 = (1/val38[1]);
          float2 val39 = *((float2*)(data7+alu17));
          float alu51 = (1/val39[0]);
          float alu52 = (1/val39[1]);
          float2 val40 = *((float2*)(data7+alu18));
          float alu53 = (1/val40[0]);
          float alu54 = (1/val40[1]);
          float2 val41 = *((float2*)(data7+alu19));
          float alu55 = (1/val41[0]);
          float alu56 = (1/val41[1]);
          float2 val42 = *((float2*)(data7+alu20));
          float alu57 = (1/val42[0]);
          float alu58 = (1/val42[1]);
          float2 val43 = *((float2*)(data7+alu1));
          float alu59 = (1/val43[0]);
          float alu60 = (1/val43[1]);
          float2 val44 = *((float2*)(data8+alu2));
          float2 val45 = *((float2*)(data8+alu3));
          float2 val46 = *((float2*)(data8+alu4));
          float2 val47 = *((float2*)(data8+alu5));
          float2 val48 = *((float2*)(data8+alu6));
          float2 val49 = *((float2*)(data8+alu7));
          float2 val50 = *((float2*)(data8+alu8));
          float2 val51 = *((float2*)(data8+alu9));
          float2 val52 = *((float2*)(data8+alu10));
          float2 val53 = *((float2*)(data8+alu11));
          float2 val54 = *((float2*)(data8+alu12));
          float2 val55 = *((float2*)(data8+alu13));
          float2 val56 = *((float2*)(data8+alu14));
          float2 val57 = *((float2*)(data8+alu15));
          float2 val58 = *((float2*)(data8+alu16));
          float2 val59 = *((float2*)(data8+alu17));
          float2 val60 = *((float2*)(data8+alu18));
          float2 val61 = *((float2*)(data8+alu19));
          float2 val62 = *((float2*)(data8+alu20));
          float2 val63 = *((float2*)(data8+alu1));
          float4 val64 = *((float4*)(data1+alu0+4));
          float4 val65 = *((float4*)(data1+alu0+8));
          float4 val66 = *((float4*)(data1+alu0+12));
          float4 val67 = *((float4*)(data1+alu0+16));
          float4 val68 = *((float4*)(data1+alu0+25600));
          float4 val69 = *((float4*)(data1+alu0+25604));
          float4 val70 = *((float4*)(data1+alu0+25608));
          float4 val71 = *((float4*)(data1+alu0+25612));
          float4 val72 = *((float4*)(data1+alu0+25616));
          acc1 = (acc1+((float)((((((val68[0]-val0)*val1*val2)+val3)!=val8[0])!=1))*alu29*val48[0])+((float)((((((val68[1]-val0)*val1*val2)+val3)!=val8[0])!=1))*alu29*val48[0])+((float)((((((val68[2]-val0)*val1*val2)+val3)!=val8[1])!=1))*alu30*val48[1])+((float)((((((val68[3]-val0)*val1*val2)+val3)!=val8[1])!=1))*alu30*val48[1])+((float)((((((val69[0]-val0)*val1*val2)+val3)!=val9[0])!=1))*alu31*val49[0])+((float)((((((val69[1]-val0)*val1*val2)+val3)!=val9[0])!=1))*alu31*val49[0])+((float)((((((val69[2]-val0)*val1*val2)+val3)!=val9[1])!=1))*alu32*val49[1])+((float)((((((val69[3]-val0)*val1*val2)+val3)!=val9[1])!=1))*alu32*val49[1])+((float)((((((val70[0]-val0)*val1*val2)+val3)!=val10[0])!=1))*alu33*val50[0])+((float)((((((val70[1]-val0)*val1*val2)+val3)!=val10[0])!=1))*alu33*val50[0])+((float)((((((val70[2]-val0)*val1*val2)+val3)!=val10[1])!=1))*alu34*val50[1])+((float)((((((val70[3]-val0)*val1*val2)+val3)!=val10[1])!=1))*alu34*val50[1])+((float)((((((val71[0]-val0)*val1*val2)+val3)!=val11[0])!=1))*alu35*val51[0])+((float)((((((val71[1]-val0)*val1*val2)+val3)!=val11[0])!=1))*alu35*val51[0])+((float)((((((val71[2]-val0)*val1*val2)+val3)!=val11[1])!=1))*alu36*val51[1])+((float)((((((val71[3]-val0)*val1*val2)+val3)!=val11[1])!=1))*alu36*val51[1])+((float)((((((val72[0]-val0)*val1*val2)+val3)!=val12[0])!=1))*alu37*val52[0])+((float)((((((val72[1]-val0)*val1*val2)+val3)!=val12[0])!=1))*alu37*val52[0])+((float)((((((val72[2]-val0)*val1*val2)+val3)!=val12[1])!=1))*alu38*val52[1])+((float)((((((val72[3]-val0)*val1*val2)+val3)!=val12[1])!=1))*alu38*val52[1]));
          float4 val73 = *((float4*)(data1+alu0+51200));
          float4 val74 = *((float4*)(data1+alu0+51204));
          float4 val75 = *((float4*)(data1+alu0+51208));
          float4 val76 = *((float4*)(data1+alu0+51212));
          float4 val77 = *((float4*)(data1+alu0+51216));
          acc2 = (acc2+((float)((((((val73[0]-val0)*val1*val2)+val3)!=val13[0])!=1))*alu39*val53[0])+((float)((((((val73[1]-val0)*val1*val2)+val3)!=val13[0])!=1))*alu39*val53[0])+((float)((((((val73[2]-val0)*val1*val2)+val3)!=val13[1])!=1))*alu40*val53[1])+((float)((((((val73[3]-val0)*val1*val2)+val3)!=val13[1])!=1))*alu40*val53[1])+((float)((((((val74[0]-val0)*val1*val2)+val3)!=val14[0])!=1))*alu41*val54[0])+((float)((((((val74[1]-val0)*val1*val2)+val3)!=val14[0])!=1))*alu41*val54[0])+((float)((((((val74[2]-val0)*val1*val2)+val3)!=val14[1])!=1))*alu42*val54[1])+((float)((((((val74[3]-val0)*val1*val2)+val3)!=val14[1])!=1))*alu42*val54[1])+((float)((((((val75[0]-val0)*val1*val2)+val3)!=val15[0])!=1))*alu43*val55[0])+((float)((((((val75[1]-val0)*val1*val2)+val3)!=val15[0])!=1))*alu43*val55[0])+((float)((((((val75[2]-val0)*val1*val2)+val3)!=val15[1])!=1))*alu44*val55[1])+((float)((((((val75[3]-val0)*val1*val2)+val3)!=val15[1])!=1))*alu44*val55[1])+((float)((((((val76[0]-val0)*val1*val2)+val3)!=val16[0])!=1))*alu45*val56[0])+((float)((((((val76[1]-val0)*val1*val2)+val3)!=val16[0])!=1))*alu45*val56[0])+((float)((((((val76[2]-val0)*val1*val2)+val3)!=val16[1])!=1))*alu46*val56[1])+((float)((((((val76[3]-val0)*val1*val2)+val3)!=val16[1])!=1))*alu46*val56[1])+((float)((((((val77[0]-val0)*val1*val2)+val3)!=val17[0])!=1))*alu47*val57[0])+((float)((((((val77[1]-val0)*val1*val2)+val3)!=val17[0])!=1))*alu47*val57[0])+((float)((((((val77[2]-val0)*val1*val2)+val3)!=val17[1])!=1))*alu48*val57[1])+((float)((((((val77[3]-val0)*val1*val2)+val3)!=val17[1])!=1))*alu48*val57[1]));
          float4 val78 = *((float4*)(data1+alu0+76800));
          float4 val79 = *((float4*)(data1+alu0+76804));
          float4 val80 = *((float4*)(data1+alu0+76808));
          float4 val81 = *((float4*)(data1+alu0+76812));
          float4 val82 = *((float4*)(data1+alu0+76816));
          acc3 = (acc3+((float)((((((val78[0]-val0)*val1*val2)+val3)!=val18[0])!=1))*alu49*val58[0])+((float)((((((val78[1]-val0)*val1*val2)+val3)!=val18[0])!=1))*alu49*val58[0])+((float)((((((val78[2]-val0)*val1*val2)+val3)!=val18[1])!=1))*alu50*val58[1])+((float)((((((val78[3]-val0)*val1*val2)+val3)!=val18[1])!=1))*alu50*val58[1])+((float)((((((val79[0]-val0)*val1*val2)+val3)!=val19[0])!=1))*alu51*val59[0])+((float)((((((val79[1]-val0)*val1*val2)+val3)!=val19[0])!=1))*alu51*val59[0])+((float)((((((val79[2]-val0)*val1*val2)+val3)!=val19[1])!=1))*alu52*val59[1])+((float)((((((val79[3]-val0)*val1*val2)+val3)!=val19[1])!=1))*alu52*val59[1])+((float)((((((val80[0]-val0)*val1*val2)+val3)!=val20[0])!=1))*alu53*val60[0])+((float)((((((val80[1]-val0)*val1*val2)+val3)!=val20[0])!=1))*alu53*val60[0])+((float)((((((val80[2]-val0)*val1*val2)+val3)!=val20[1])!=1))*alu54*val60[1])+((float)((((((val80[3]-val0)*val1*val2)+val3)!=val20[1])!=1))*alu54*val60[1])+((float)((((((val81[0]-val0)*val1*val2)+val3)!=val21[0])!=1))*alu55*val61[0])+((float)((((((val81[1]-val0)*val1*val2)+val3)!=val21[0])!=1))*alu55*val61[0])+((float)((((((val81[2]-val0)*val1*val2)+val3)!=val21[1])!=1))*alu56*val61[1])+((float)((((((val81[3]-val0)*val1*val2)+val3)!=val21[1])!=1))*alu56*val61[1])+((float)((((((val82[0]-val0)*val1*val2)+val3)!=val22[0])!=1))*alu57*val62[0])+((float)((((((val82[1]-val0)*val1*val2)+val3)!=val22[0])!=1))*alu57*val62[0])+((float)((((((val82[2]-val0)*val1*val2)+val3)!=val22[1])!=1))*alu58*val62[1])+((float)((((((val82[3]-val0)*val1*val2)+val3)!=val22[1])!=1))*alu58*val62[1]));
          float4 val83 = *((float4*)(data1+alu0));
          acc0 = (acc0+((float)((((((val83[0]-val0)*val1*val2)+val3)!=val23[0])!=1))*alu59*val63[0])+((float)((((((val83[1]-val0)*val1*val2)+val3)!=val23[0])!=1))*alu59*val63[0])+((float)((((((val83[2]-val0)*val1*val2)+val3)!=val23[1])!=1))*alu60*val63[1])+((float)((((((val83[3]-val0)*val1*val2)+val3)!=val23[1])!=1))*alu60*val63[1])+((float)((((((val64[0]-val0)*val1*val2)+val3)!=val4[0])!=1))*alu21*val44[0])+((float)((((((val64[1]-val0)*val1*val2)+val3)!=val4[0])!=1))*alu21*val44[0])+((float)((((((val64[2]-val0)*val1*val2)+val3)!=val4[1])!=1))*alu22*val44[1])+((float)((((((val64[3]-val0)*val1*val2)+val3)!=val4[1])!=1))*alu22*val44[1])+((float)((((((val65[0]-val0)*val1*val2)+val3)!=val5[0])!=1))*alu23*val45[0])+((float)((((((val65[1]-val0)*val1*val2)+val3)!=val5[0])!=1))*alu23*val45[0])+((float)((((((val65[2]-val0)*val1*val2)+val3)!=val5[1])!=1))*alu24*val45[1])+((float)((((((val65[3]-val0)*val1*val2)+val3)!=val5[1])!=1))*alu24*val45[1])+((float)((((((val66[0]-val0)*val1*val2)+val3)!=val6[0])!=1))*alu25*val46[0])+((float)((((((val66[1]-val0)*val1*val2)+val3)!=val6[0])!=1))*alu25*val46[0])+((float)((((((val66[2]-val0)*val1*val2)+val3)!=val6[1])!=1))*alu26*val46[1])+((float)((((((val66[3]-val0)*val1*val2)+val3)!=val6[1])!=1))*alu26*val46[1])+((float)((((((val67[0]-val0)*val1*val2)+val3)!=val7[0])!=1))*alu27*val47[0])+((float)((((((val67[1]-val0)*val1*val2)+val3)!=val7[0])!=1))*alu27*val47[0])+((float)((((((val67[2]-val0)*val1*val2)+val3)!=val7[1])!=1))*alu28*val47[1])+((float)((((((val67[3]-val0)*val1*val2)+val3)!=val7[1])!=1))*alu28*val47[1]));
        }
      }
      *((float4*)(data0+(ridx0<<8)+(ridx1<<2))) = (float4){acc0,acc1,acc2,acc3};
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_64_4n2(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float4 val0 = *((float4*)(data1+(ridx0<<8)+(ridx1<<2)));
      acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
    }
    float val1 = *(data2+ridx0);
    float val2 = *(data3+ridx0);
    float alu0 = ((val2*4.882812390860636e-06f)+1e-05f);
    *(data0+ridx0) = (acc0*(1/(val1*alu0*alu0*2.0f))*-4.882812390860636e-06f);
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_64_4(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float4 val0 = *((float4*)(data1+(ridx0<<8)+(ridx1<<2)));
      acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
    }
    *(data0+ridx0) = (acc0*4.882812390860636e-06f);
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_64_4n1(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float4 val0 = *((float4*)(data1+(ridx0<<8)+(ridx1<<2)));
      acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
    }
    *(data0+ridx0) = acc0;
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_512_32_20_5_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6, float* restrict data7, float* restrict data8, float* restrict data9, float* restrict data10) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 32; ridx1++) {
      for (int ridx2 = 0; ridx2 < 20; ridx2++) {
        for (int ridx3 = 0; ridx3 < 5; ridx3++) {
          int alu0 = ((ridx3<<1)+((ridx2>>1)*10)+(ridx0*3200)+(ridx1*100));
          int alu1 = ((ridx0*12800)+(ridx1*400)+(ridx2*20)+(ridx3<<2));
          float val0 = *(data2+ridx1);
          float val1 = *(data3+ridx1);
          float val2 = *(data4+ridx1);
          float val3 = *(data5+ridx1);
          float val4 = *(data6+ridx1);
          float val5 = *(data10+ridx1);
          float2 val6 = *((float2*)(data7+alu0));
          float2 val7 = *((float2*)(data8+alu0));
          float alu2 = (1/val7[0]);
          float alu3 = (1/val7[1]);
          float2 val8 = *((float2*)(data9+alu0));
          float4 val9 = *((float4*)(data1+alu1));
          float alu4 = (val9[0]-val0);
          float alu5 = (val9[1]-val0);
          float alu6 = (val9[2]-val0);
          float alu7 = (val9[3]-val0);
          *((float4*)(data0+alu1)) = (float4){((float)((0.0f<val9[0]))*((alu4*val1*2.0f)+(val2*val3*(float)(((((alu4*val2*val3)+val4)!=val6[0])!=1))*alu2*val8[0])+val5)),((float)((0.0f<val9[1]))*((alu5*val1*2.0f)+(val2*val3*(float)(((((alu5*val2*val3)+val4)!=val6[0])!=1))*alu2*val8[0])+val5)),((float)((0.0f<val9[2]))*((alu6*val1*2.0f)+(val2*val3*(float)(((((alu6*val2*val3)+val4)!=val6[1])!=1))*alu3*val8[1])+val5)),((float)((0.0f<val9[3]))*((alu7*val1*2.0f)+(val2*val3*(float)(((((alu7*val2*val3)+val4)!=val6[1])!=1))*alu3*val8[1])+val5))};
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_8_4n11(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 8; ridx0++) {
    int alu0 = (ridx0<<2);
    float4 val0 = *((float4*)(data0+alu0));
    float4 val1 = *((float4*)(data1+alu0));
    *((float4*)(data0+alu0)) = (float4){((val0[0]*0.9f)+(val1[0]*0.09999999999999998f)),((val0[1]*0.9f)+(val1[1]*0.09999999999999998f)),((val0[2]*0.9f)+(val1[2]*0.09999999999999998f)),((val0[3]*0.9f)+(val1[3]*0.09999999999999998f))};
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_8_4n12(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 8; ridx0++) {
    int alu0 = (ridx0<<2);
    float4 val0 = *((float4*)(data0+alu0));
    float4 val1 = *((float4*)(data1+alu0));
    *((float4*)(data0+alu0)) = (float4){((val0[0]*0.999f)+(val1[0]*val1[0]*0.0010000000000000009f)),((val0[1]*0.999f)+(val1[1]*val1[1]*0.0010000000000000009f)),((val0[2]*0.999f)+(val1[2]*val1[2]*0.0010000000000000009f)),((val0[3]*0.999f)+(val1[3]*val1[3]*0.0010000000000000009f))};
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_512_8_100_25_4_4_32(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 8; ridx1++) {
      for (int ridx2 = 0; ridx2 < 100; ridx2++) {
        int alu0 = ((ridx0*12800)+(ridx2<<2));
        for (int ridx3 = 0; ridx3 < 25; ridx3++) {
          int alu1 = ((ridx0*320000)+(ridx1*40000)+(ridx2*100)+ridx3);
          int alu2 = ((ridx1*100)+ridx3);
          float val0 = *(data1+alu2+25);
          float val1 = *(data1+alu2+50);
          float val2 = *(data1+alu2+75);
          float val3 = *(data1+alu2+800);
          float val4 = *(data1+alu2+825);
          float val5 = *(data1+alu2+850);
          float val6 = *(data1+alu2+875);
          float val7 = *(data1+alu2+1600);
          float val8 = *(data1+alu2+1625);
          float val9 = *(data1+alu2+1650);
          float val10 = *(data1+alu2+1675);
          float val11 = *(data1+alu2+2400);
          float val12 = *(data1+alu2+2425);
          float val13 = *(data1+alu2+2450);
          float val14 = *(data1+alu2+2475);
          float val15 = *(data1+alu2+3200);
          float val16 = *(data1+alu2+3225);
          float val17 = *(data1+alu2+3250);
          float val18 = *(data1+alu2+3275);
          float val19 = *(data1+alu2+4000);
          float val20 = *(data1+alu2+4025);
          float val21 = *(data1+alu2+4050);
          float val22 = *(data1+alu2+4075);
          float val23 = *(data1+alu2+4800);
          float val24 = *(data1+alu2+4825);
          float val25 = *(data1+alu2+4850);
          float val26 = *(data1+alu2+4875);
          float val27 = *(data1+alu2+5600);
          float val28 = *(data1+alu2+5625);
          float val29 = *(data1+alu2+5650);
          float val30 = *(data1+alu2+5675);
          float val31 = *(data1+alu2+6400);
          float val32 = *(data1+alu2+6425);
          float val33 = *(data1+alu2+6450);
          float val34 = *(data1+alu2+6475);
          float val35 = *(data1+alu2+7200);
          float val36 = *(data1+alu2+7225);
          float val37 = *(data1+alu2+7250);
          float val38 = *(data1+alu2+7275);
          float val39 = *(data1+alu2+8000);
          float val40 = *(data1+alu2+8025);
          float val41 = *(data1+alu2+8050);
          float val42 = *(data1+alu2+8075);
          float val43 = *(data1+alu2+8800);
          float val44 = *(data1+alu2+8825);
          float val45 = *(data1+alu2+8850);
          float val46 = *(data1+alu2+8875);
          float val47 = *(data1+alu2+9600);
          float val48 = *(data1+alu2+9625);
          float val49 = *(data1+alu2+9650);
          float val50 = *(data1+alu2+9675);
          float val51 = *(data1+alu2+10400);
          float val52 = *(data1+alu2+10425);
          float val53 = *(data1+alu2+10450);
          float val54 = *(data1+alu2+10475);
          float val55 = *(data1+alu2+11200);
          float val56 = *(data1+alu2+11225);
          float val57 = *(data1+alu2+11250);
          float val58 = *(data1+alu2+11275);
          float val59 = *(data1+alu2+12000);
          float val60 = *(data1+alu2+12025);
          float val61 = *(data1+alu2+12050);
          float val62 = *(data1+alu2+12075);
          float val63 = *(data1+alu2+12800);
          float val64 = *(data1+alu2+12825);
          float val65 = *(data1+alu2+12850);
          float val66 = *(data1+alu2+12875);
          float val67 = *(data1+alu2+13600);
          float val68 = *(data1+alu2+13625);
          float val69 = *(data1+alu2+13650);
          float val70 = *(data1+alu2+13675);
          float val71 = *(data1+alu2+14400);
          float val72 = *(data1+alu2+14425);
          float val73 = *(data1+alu2+14450);
          float val74 = *(data1+alu2+14475);
          float val75 = *(data1+alu2+15200);
          float val76 = *(data1+alu2+15225);
          float val77 = *(data1+alu2+15250);
          float val78 = *(data1+alu2+15275);
          float val79 = *(data1+alu2+16000);
          float val80 = *(data1+alu2+16025);
          float val81 = *(data1+alu2+16050);
          float val82 = *(data1+alu2+16075);
          float val83 = *(data1+alu2+16800);
          float val84 = *(data1+alu2+16825);
          float val85 = *(data1+alu2+16850);
          float val86 = *(data1+alu2+16875);
          float val87 = *(data1+alu2+17600);
          float val88 = *(data1+alu2+17625);
          float val89 = *(data1+alu2+17650);
          float val90 = *(data1+alu2+17675);
          float val91 = *(data1+alu2+18400);
          float val92 = *(data1+alu2+18425);
          float val93 = *(data1+alu2+18450);
          float val94 = *(data1+alu2+18475);
          float val95 = *(data1+alu2+19200);
          float val96 = *(data1+alu2+19225);
          float val97 = *(data1+alu2+19250);
          float val98 = *(data1+alu2+19275);
          float val99 = *(data1+alu2+20000);
          float val100 = *(data1+alu2+20025);
          float val101 = *(data1+alu2+20050);
          float val102 = *(data1+alu2+20075);
          float val103 = *(data1+alu2+20800);
          float val104 = *(data1+alu2+20825);
          float val105 = *(data1+alu2+20850);
          float val106 = *(data1+alu2+20875);
          float val107 = *(data1+alu2+21600);
          float val108 = *(data1+alu2+21625);
          float val109 = *(data1+alu2+21650);
          float val110 = *(data1+alu2+21675);
          float val111 = *(data1+alu2+22400);
          float val112 = *(data1+alu2+22425);
          float val113 = *(data1+alu2+22450);
          float val114 = *(data1+alu2+22475);
          float val115 = *(data1+alu2+23200);
          float val116 = *(data1+alu2+23225);
          float val117 = *(data1+alu2+23250);
          float val118 = *(data1+alu2+23275);
          float val119 = *(data1+alu2+24000);
          float val120 = *(data1+alu2+24025);
          float val121 = *(data1+alu2+24050);
          float val122 = *(data1+alu2+24075);
          float val123 = *(data1+alu2+24800);
          float val124 = *(data1+alu2+24825);
          float val125 = *(data1+alu2+24850);
          float val126 = *(data1+alu2+24875);
          float val127 = *(data1+alu2);
          float4 val128 = *((float4*)(data2+alu0+400));
          float4 val129 = *((float4*)(data2+alu0+800));
          float4 val130 = *((float4*)(data2+alu0+1200));
          float4 val131 = *((float4*)(data2+alu0+1600));
          float4 val132 = *((float4*)(data2+alu0+2000));
          float4 val133 = *((float4*)(data2+alu0+2400));
          float4 val134 = *((float4*)(data2+alu0+2800));
          float4 val135 = *((float4*)(data2+alu0+3200));
          float4 val136 = *((float4*)(data2+alu0+3600));
          float4 val137 = *((float4*)(data2+alu0+4000));
          float4 val138 = *((float4*)(data2+alu0+4400));
          float4 val139 = *((float4*)(data2+alu0+4800));
          float4 val140 = *((float4*)(data2+alu0+5200));
          float4 val141 = *((float4*)(data2+alu0+5600));
          float4 val142 = *((float4*)(data2+alu0+6000));
          float4 val143 = *((float4*)(data2+alu0+6400));
          float4 val144 = *((float4*)(data2+alu0+6800));
          float4 val145 = *((float4*)(data2+alu0+7200));
          float4 val146 = *((float4*)(data2+alu0+7600));
          float4 val147 = *((float4*)(data2+alu0+8000));
          float4 val148 = *((float4*)(data2+alu0+8400));
          float4 val149 = *((float4*)(data2+alu0+8800));
          float4 val150 = *((float4*)(data2+alu0+9200));
          float4 val151 = *((float4*)(data2+alu0+9600));
          float4 val152 = *((float4*)(data2+alu0+10000));
          float4 val153 = *((float4*)(data2+alu0+10400));
          float4 val154 = *((float4*)(data2+alu0+10800));
          float4 val155 = *((float4*)(data2+alu0+11200));
          float4 val156 = *((float4*)(data2+alu0+11600));
          float4 val157 = *((float4*)(data2+alu0+12000));
          float4 val158 = *((float4*)(data2+alu0+12400));
          float4 val159 = *((float4*)(data2+alu0));
          *(data0+alu1+25) = ((val127*val159[1])+(val3*val128[1])+(val7*val129[1])+(val11*val130[1])+(val15*val131[1])+(val19*val132[1])+(val23*val133[1])+(val27*val134[1])+(val31*val135[1])+(val35*val136[1])+(val39*val137[1])+(val43*val138[1])+(val47*val139[1])+(val51*val140[1])+(val55*val141[1])+(val59*val142[1])+(val63*val143[1])+(val67*val144[1])+(val71*val145[1])+(val75*val146[1])+(val79*val147[1])+(val83*val148[1])+(val87*val149[1])+(val91*val150[1])+(val95*val151[1])+(val99*val152[1])+(val103*val153[1])+(val107*val154[1])+(val111*val155[1])+(val115*val156[1])+(val119*val157[1])+(val123*val158[1]));
          *(data0+alu1+50) = ((val127*val159[2])+(val3*val128[2])+(val7*val129[2])+(val11*val130[2])+(val15*val131[2])+(val19*val132[2])+(val23*val133[2])+(val27*val134[2])+(val31*val135[2])+(val35*val136[2])+(val39*val137[2])+(val43*val138[2])+(val47*val139[2])+(val51*val140[2])+(val55*val141[2])+(val59*val142[2])+(val63*val143[2])+(val67*val144[2])+(val71*val145[2])+(val75*val146[2])+(val79*val147[2])+(val83*val148[2])+(val87*val149[2])+(val91*val150[2])+(val95*val151[2])+(val99*val152[2])+(val103*val153[2])+(val107*val154[2])+(val111*val155[2])+(val115*val156[2])+(val119*val157[2])+(val123*val158[2]));
          *(data0+alu1+75) = ((val127*val159[3])+(val3*val128[3])+(val7*val129[3])+(val11*val130[3])+(val15*val131[3])+(val19*val132[3])+(val23*val133[3])+(val27*val134[3])+(val31*val135[3])+(val35*val136[3])+(val39*val137[3])+(val43*val138[3])+(val47*val139[3])+(val51*val140[3])+(val55*val141[3])+(val59*val142[3])+(val63*val143[3])+(val67*val144[3])+(val71*val145[3])+(val75*val146[3])+(val79*val147[3])+(val83*val148[3])+(val87*val149[3])+(val91*val150[3])+(val95*val151[3])+(val99*val152[3])+(val103*val153[3])+(val107*val154[3])+(val111*val155[3])+(val115*val156[3])+(val119*val157[3])+(val123*val158[3]));
          *(data0+alu1+10000) = ((val0*val159[0])+(val4*val128[0])+(val8*val129[0])+(val12*val130[0])+(val16*val131[0])+(val20*val132[0])+(val24*val133[0])+(val28*val134[0])+(val32*val135[0])+(val36*val136[0])+(val40*val137[0])+(val44*val138[0])+(val48*val139[0])+(val52*val140[0])+(val56*val141[0])+(val60*val142[0])+(val64*val143[0])+(val68*val144[0])+(val72*val145[0])+(val76*val146[0])+(val80*val147[0])+(val84*val148[0])+(val88*val149[0])+(val92*val150[0])+(val96*val151[0])+(val100*val152[0])+(val104*val153[0])+(val108*val154[0])+(val112*val155[0])+(val116*val156[0])+(val120*val157[0])+(val124*val158[0]));
          *(data0+alu1+10025) = ((val0*val159[1])+(val4*val128[1])+(val8*val129[1])+(val12*val130[1])+(val16*val131[1])+(val20*val132[1])+(val24*val133[1])+(val28*val134[1])+(val32*val135[1])+(val36*val136[1])+(val40*val137[1])+(val44*val138[1])+(val48*val139[1])+(val52*val140[1])+(val56*val141[1])+(val60*val142[1])+(val64*val143[1])+(val68*val144[1])+(val72*val145[1])+(val76*val146[1])+(val80*val147[1])+(val84*val148[1])+(val88*val149[1])+(val92*val150[1])+(val96*val151[1])+(val100*val152[1])+(val104*val153[1])+(val108*val154[1])+(val112*val155[1])+(val116*val156[1])+(val120*val157[1])+(val124*val158[1]));
          *(data0+alu1+10050) = ((val0*val159[2])+(val4*val128[2])+(val8*val129[2])+(val12*val130[2])+(val16*val131[2])+(val20*val132[2])+(val24*val133[2])+(val28*val134[2])+(val32*val135[2])+(val36*val136[2])+(val40*val137[2])+(val44*val138[2])+(val48*val139[2])+(val52*val140[2])+(val56*val141[2])+(val60*val142[2])+(val64*val143[2])+(val68*val144[2])+(val72*val145[2])+(val76*val146[2])+(val80*val147[2])+(val84*val148[2])+(val88*val149[2])+(val92*val150[2])+(val96*val151[2])+(val100*val152[2])+(val104*val153[2])+(val108*val154[2])+(val112*val155[2])+(val116*val156[2])+(val120*val157[2])+(val124*val158[2]));
          *(data0+alu1+10075) = ((val0*val159[3])+(val4*val128[3])+(val8*val129[3])+(val12*val130[3])+(val16*val131[3])+(val20*val132[3])+(val24*val133[3])+(val28*val134[3])+(val32*val135[3])+(val36*val136[3])+(val40*val137[3])+(val44*val138[3])+(val48*val139[3])+(val52*val140[3])+(val56*val141[3])+(val60*val142[3])+(val64*val143[3])+(val68*val144[3])+(val72*val145[3])+(val76*val146[3])+(val80*val147[3])+(val84*val148[3])+(val88*val149[3])+(val92*val150[3])+(val96*val151[3])+(val100*val152[3])+(val104*val153[3])+(val108*val154[3])+(val112*val155[3])+(val116*val156[3])+(val120*val157[3])+(val124*val158[3]));
          *(data0+alu1+20000) = ((val1*val159[0])+(val5*val128[0])+(val9*val129[0])+(val13*val130[0])+(val17*val131[0])+(val21*val132[0])+(val25*val133[0])+(val29*val134[0])+(val33*val135[0])+(val37*val136[0])+(val41*val137[0])+(val45*val138[0])+(val49*val139[0])+(val53*val140[0])+(val57*val141[0])+(val61*val142[0])+(val65*val143[0])+(val69*val144[0])+(val73*val145[0])+(val77*val146[0])+(val81*val147[0])+(val85*val148[0])+(val89*val149[0])+(val93*val150[0])+(val97*val151[0])+(val101*val152[0])+(val105*val153[0])+(val109*val154[0])+(val113*val155[0])+(val117*val156[0])+(val121*val157[0])+(val125*val158[0]));
          *(data0+alu1+20025) = ((val1*val159[1])+(val5*val128[1])+(val9*val129[1])+(val13*val130[1])+(val17*val131[1])+(val21*val132[1])+(val25*val133[1])+(val29*val134[1])+(val33*val135[1])+(val37*val136[1])+(val41*val137[1])+(val45*val138[1])+(val49*val139[1])+(val53*val140[1])+(val57*val141[1])+(val61*val142[1])+(val65*val143[1])+(val69*val144[1])+(val73*val145[1])+(val77*val146[1])+(val81*val147[1])+(val85*val148[1])+(val89*val149[1])+(val93*val150[1])+(val97*val151[1])+(val101*val152[1])+(val105*val153[1])+(val109*val154[1])+(val113*val155[1])+(val117*val156[1])+(val121*val157[1])+(val125*val158[1]));
          *(data0+alu1+20050) = ((val1*val159[2])+(val5*val128[2])+(val9*val129[2])+(val13*val130[2])+(val17*val131[2])+(val21*val132[2])+(val25*val133[2])+(val29*val134[2])+(val33*val135[2])+(val37*val136[2])+(val41*val137[2])+(val45*val138[2])+(val49*val139[2])+(val53*val140[2])+(val57*val141[2])+(val61*val142[2])+(val65*val143[2])+(val69*val144[2])+(val73*val145[2])+(val77*val146[2])+(val81*val147[2])+(val85*val148[2])+(val89*val149[2])+(val93*val150[2])+(val97*val151[2])+(val101*val152[2])+(val105*val153[2])+(val109*val154[2])+(val113*val155[2])+(val117*val156[2])+(val121*val157[2])+(val125*val158[2]));
          *(data0+alu1+20075) = ((val1*val159[3])+(val5*val128[3])+(val9*val129[3])+(val13*val130[3])+(val17*val131[3])+(val21*val132[3])+(val25*val133[3])+(val29*val134[3])+(val33*val135[3])+(val37*val136[3])+(val41*val137[3])+(val45*val138[3])+(val49*val139[3])+(val53*val140[3])+(val57*val141[3])+(val61*val142[3])+(val65*val143[3])+(val69*val144[3])+(val73*val145[3])+(val77*val146[3])+(val81*val147[3])+(val85*val148[3])+(val89*val149[3])+(val93*val150[3])+(val97*val151[3])+(val101*val152[3])+(val105*val153[3])+(val109*val154[3])+(val113*val155[3])+(val117*val156[3])+(val121*val157[3])+(val125*val158[3]));
          *(data0+alu1+30000) = ((val2*val159[0])+(val6*val128[0])+(val10*val129[0])+(val14*val130[0])+(val18*val131[0])+(val22*val132[0])+(val26*val133[0])+(val30*val134[0])+(val34*val135[0])+(val38*val136[0])+(val42*val137[0])+(val46*val138[0])+(val50*val139[0])+(val54*val140[0])+(val58*val141[0])+(val62*val142[0])+(val66*val143[0])+(val70*val144[0])+(val74*val145[0])+(val78*val146[0])+(val82*val147[0])+(val86*val148[0])+(val90*val149[0])+(val94*val150[0])+(val98*val151[0])+(val102*val152[0])+(val106*val153[0])+(val110*val154[0])+(val114*val155[0])+(val118*val156[0])+(val122*val157[0])+(val126*val158[0]));
          *(data0+alu1+30025) = ((val2*val159[1])+(val6*val128[1])+(val10*val129[1])+(val14*val130[1])+(val18*val131[1])+(val22*val132[1])+(val26*val133[1])+(val30*val134[1])+(val34*val135[1])+(val38*val136[1])+(val42*val137[1])+(val46*val138[1])+(val50*val139[1])+(val54*val140[1])+(val58*val141[1])+(val62*val142[1])+(val66*val143[1])+(val70*val144[1])+(val74*val145[1])+(val78*val146[1])+(val82*val147[1])+(val86*val148[1])+(val90*val149[1])+(val94*val150[1])+(val98*val151[1])+(val102*val152[1])+(val106*val153[1])+(val110*val154[1])+(val114*val155[1])+(val118*val156[1])+(val122*val157[1])+(val126*val158[1]));
          *(data0+alu1+30050) = ((val2*val159[2])+(val6*val128[2])+(val10*val129[2])+(val14*val130[2])+(val18*val131[2])+(val22*val132[2])+(val26*val133[2])+(val30*val134[2])+(val34*val135[2])+(val38*val136[2])+(val42*val137[2])+(val46*val138[2])+(val50*val139[2])+(val54*val140[2])+(val58*val141[2])+(val62*val142[2])+(val66*val143[2])+(val70*val144[2])+(val74*val145[2])+(val78*val146[2])+(val82*val147[2])+(val86*val148[2])+(val90*val149[2])+(val94*val150[2])+(val98*val151[2])+(val102*val152[2])+(val106*val153[2])+(val110*val154[2])+(val114*val155[2])+(val118*val156[2])+(val122*val157[2])+(val126*val158[2]));
          *(data0+alu1+30075) = ((val2*val159[3])+(val6*val128[3])+(val10*val129[3])+(val14*val130[3])+(val18*val131[3])+(val22*val132[3])+(val26*val133[3])+(val30*val134[3])+(val34*val135[3])+(val38*val136[3])+(val42*val137[3])+(val46*val138[3])+(val50*val139[3])+(val54*val140[3])+(val58*val141[3])+(val62*val142[3])+(val66*val143[3])+(val70*val144[3])+(val74*val145[3])+(val78*val146[3])+(val82*val147[3])+(val86*val148[3])+(val90*val149[3])+(val94*val150[3])+(val98*val151[3])+(val102*val152[3])+(val106*val153[3])+(val110*val154[3])+(val114*val155[3])+(val118*val156[3])+(val122*val157[3])+(val126*val158[3]));
          *(data0+alu1) = ((val127*val159[0])+(val3*val128[0])+(val7*val129[0])+(val11*val130[0])+(val15*val131[0])+(val19*val132[0])+(val23*val133[0])+(val27*val134[0])+(val31*val135[0])+(val35*val136[0])+(val39*val137[0])+(val43*val138[0])+(val47*val139[0])+(val51*val140[0])+(val55*val141[0])+(val59*val142[0])+(val63*val143[0])+(val67*val144[0])+(val71*val145[0])+(val75*val146[0])+(val79*val147[0])+(val83*val148[0])+(val87*val149[0])+(val91*val150[0])+(val95*val151[0])+(val99*val152[0])+(val103*val153[0])+(val107*val154[0])+(val111*val155[0])+(val115*val156[0])+(val119*val157[0])+(val123*val158[0]));
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_8_8_5_5_128_4_20_4_4_20(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 8; ridx0++) {
    for (int ridx1 = 0; ridx1 < 8; ridx1++) {
      for (int ridx2 = 0; ridx2 < 5; ridx2++) {
        for (int ridx3 = 0; ridx3 < 5; ridx3++) {
          for (int ridx4 = 0; ridx4 < 128; ridx4++) {
            int alu0 = ((ridx0*409600)+(ridx1*12800)+(ridx2*640)+(ridx3<<7)+ridx4);
            float acc0 = 0.0f;
            float acc1 = 0.0f;
            float acc2 = 0.0f;
            float acc3 = 0.0f;
            float acc4 = 0.0f;
            float acc5 = 0.0f;
            float acc6 = 0.0f;
            float acc7 = 0.0f;
            float acc8 = 0.0f;
            float acc9 = 0.0f;
            float acc10 = 0.0f;
            float acc11 = 0.0f;
            float acc12 = 0.0f;
            float acc13 = 0.0f;
            float acc14 = 0.0f;
            float acc15 = 0.0f;
            for (int ridx5 = 0; ridx5 < 4; ridx5++) {
              for (int ridx6 = 0; ridx6 < 20; ridx6++) {
                int alu1 = ((ridx1*2304)+(ridx2*24)+ridx3+(ridx4*73728)+(ridx5*18432)+(ridx6*24));
                int alu2 = ((ridx0*1600)+(ridx4*51200)+(ridx5*12800)+(ridx6*20));
                float val0 = *(data1+alu1+1);
                float val1 = *(data1+alu1+2);
                float val2 = *(data1+alu1+3);
                float val3 = *(data1+alu1+4);
                float val4 = *(data1+alu1+5);
                float val5 = *(data1+alu1+6);
                float val6 = *(data1+alu1+7);
                float val7 = *(data1+alu1+8);
                float val8 = *(data1+alu1+9);
                float val9 = *(data1+alu1+10);
                float val10 = *(data1+alu1+11);
                float val11 = *(data1+alu1+12);
                float val12 = *(data1+alu1+13);
                float val13 = *(data1+alu1+14);
                float val14 = *(data1+alu1+15);
                float val15 = *(data1+alu1+16);
                float val16 = *(data1+alu1+17);
                float val17 = *(data1+alu1+18);
                float val18 = *(data1+alu1+19);
                float val19 = *(data1+alu1+576);
                float val20 = *(data1+alu1+577);
                float val21 = *(data1+alu1+578);
                float val22 = *(data1+alu1+579);
                float val23 = *(data1+alu1+580);
                float val24 = *(data1+alu1+581);
                float val25 = *(data1+alu1+582);
                float val26 = *(data1+alu1+583);
                float val27 = *(data1+alu1+584);
                float val28 = *(data1+alu1+585);
                float val29 = *(data1+alu1+586);
                float val30 = *(data1+alu1+587);
                float val31 = *(data1+alu1+588);
                float val32 = *(data1+alu1+589);
                float val33 = *(data1+alu1+590);
                float val34 = *(data1+alu1+591);
                float val35 = *(data1+alu1+592);
                float val36 = *(data1+alu1+593);
                float val37 = *(data1+alu1+594);
                float val38 = *(data1+alu1+595);
                float val39 = *(data1+alu1+1152);
                float val40 = *(data1+alu1+1153);
                float val41 = *(data1+alu1+1154);
                float val42 = *(data1+alu1+1155);
                float val43 = *(data1+alu1+1156);
                float val44 = *(data1+alu1+1157);
                float val45 = *(data1+alu1+1158);
                float val46 = *(data1+alu1+1159);
                float val47 = *(data1+alu1+1160);
                float val48 = *(data1+alu1+1161);
                float val49 = *(data1+alu1+1162);
                float val50 = *(data1+alu1+1163);
                float val51 = *(data1+alu1+1164);
                float val52 = *(data1+alu1+1165);
                float val53 = *(data1+alu1+1166);
                float val54 = *(data1+alu1+1167);
                float val55 = *(data1+alu1+1168);
                float val56 = *(data1+alu1+1169);
                float val57 = *(data1+alu1+1170);
                float val58 = *(data1+alu1+1171);
                float val59 = *(data1+alu1+1728);
                float val60 = *(data1+alu1+1729);
                float val61 = *(data1+alu1+1730);
                float val62 = *(data1+alu1+1731);
                float val63 = *(data1+alu1+1732);
                float val64 = *(data1+alu1+1733);
                float val65 = *(data1+alu1+1734);
                float val66 = *(data1+alu1+1735);
                float val67 = *(data1+alu1+1736);
                float val68 = *(data1+alu1+1737);
                float val69 = *(data1+alu1+1738);
                float val70 = *(data1+alu1+1739);
                float val71 = *(data1+alu1+1740);
                float val72 = *(data1+alu1+1741);
                float val73 = *(data1+alu1+1742);
                float val74 = *(data1+alu1+1743);
                float val75 = *(data1+alu1+1744);
                float val76 = *(data1+alu1+1745);
                float val77 = *(data1+alu1+1746);
                float val78 = *(data1+alu1+1747);
                float val79 = *(data1+alu1);
                float4 val80 = *((float4*)(data2+alu2+4));
                float4 val81 = *((float4*)(data2+alu2+8));
                float4 val82 = *((float4*)(data2+alu2+12));
                float4 val83 = *((float4*)(data2+alu2+16));
                float4 val84 = *((float4*)(data2+alu2+400));
                float4 val85 = *((float4*)(data2+alu2+404));
                float4 val86 = *((float4*)(data2+alu2+408));
                float4 val87 = *((float4*)(data2+alu2+412));
                float4 val88 = *((float4*)(data2+alu2+416));
                acc4 = (acc4+(val79*val84[0])+(val0*val84[1])+(val1*val84[2])+(val2*val84[3])+(val3*val85[0])+(val4*val85[1])+(val5*val85[2])+(val6*val85[3])+(val7*val86[0])+(val8*val86[1])+(val9*val86[2])+(val10*val86[3])+(val11*val87[0])+(val12*val87[1])+(val13*val87[2])+(val14*val87[3])+(val15*val88[0])+(val16*val88[1])+(val17*val88[2])+(val18*val88[3]));
                acc5 = (acc5+(val19*val84[0])+(val20*val84[1])+(val21*val84[2])+(val22*val84[3])+(val23*val85[0])+(val24*val85[1])+(val25*val85[2])+(val26*val85[3])+(val27*val86[0])+(val28*val86[1])+(val29*val86[2])+(val30*val86[3])+(val31*val87[0])+(val32*val87[1])+(val33*val87[2])+(val34*val87[3])+(val35*val88[0])+(val36*val88[1])+(val37*val88[2])+(val38*val88[3]));
                acc6 = (acc6+(val39*val84[0])+(val40*val84[1])+(val41*val84[2])+(val42*val84[3])+(val43*val85[0])+(val44*val85[1])+(val45*val85[2])+(val46*val85[3])+(val47*val86[0])+(val48*val86[1])+(val49*val86[2])+(val50*val86[3])+(val51*val87[0])+(val52*val87[1])+(val53*val87[2])+(val54*val87[3])+(val55*val88[0])+(val56*val88[1])+(val57*val88[2])+(val58*val88[3]));
                acc7 = (acc7+(val59*val84[0])+(val60*val84[1])+(val61*val84[2])+(val62*val84[3])+(val63*val85[0])+(val64*val85[1])+(val65*val85[2])+(val66*val85[3])+(val67*val86[0])+(val68*val86[1])+(val69*val86[2])+(val70*val86[3])+(val71*val87[0])+(val72*val87[1])+(val73*val87[2])+(val74*val87[3])+(val75*val88[0])+(val76*val88[1])+(val77*val88[2])+(val78*val88[3]));
                float4 val89 = *((float4*)(data2+alu2+800));
                float4 val90 = *((float4*)(data2+alu2+804));
                float4 val91 = *((float4*)(data2+alu2+808));
                float4 val92 = *((float4*)(data2+alu2+812));
                float4 val93 = *((float4*)(data2+alu2+816));
                acc8 = (acc8+(val79*val89[0])+(val0*val89[1])+(val1*val89[2])+(val2*val89[3])+(val3*val90[0])+(val4*val90[1])+(val5*val90[2])+(val6*val90[3])+(val7*val91[0])+(val8*val91[1])+(val9*val91[2])+(val10*val91[3])+(val11*val92[0])+(val12*val92[1])+(val13*val92[2])+(val14*val92[3])+(val15*val93[0])+(val16*val93[1])+(val17*val93[2])+(val18*val93[3]));
                acc9 = (acc9+(val19*val89[0])+(val20*val89[1])+(val21*val89[2])+(val22*val89[3])+(val23*val90[0])+(val24*val90[1])+(val25*val90[2])+(val26*val90[3])+(val27*val91[0])+(val28*val91[1])+(val29*val91[2])+(val30*val91[3])+(val31*val92[0])+(val32*val92[1])+(val33*val92[2])+(val34*val92[3])+(val35*val93[0])+(val36*val93[1])+(val37*val93[2])+(val38*val93[3]));
                acc10 = (acc10+(val39*val89[0])+(val40*val89[1])+(val41*val89[2])+(val42*val89[3])+(val43*val90[0])+(val44*val90[1])+(val45*val90[2])+(val46*val90[3])+(val47*val91[0])+(val48*val91[1])+(val49*val91[2])+(val50*val91[3])+(val51*val92[0])+(val52*val92[1])+(val53*val92[2])+(val54*val92[3])+(val55*val93[0])+(val56*val93[1])+(val57*val93[2])+(val58*val93[3]));
                acc11 = (acc11+(val59*val89[0])+(val60*val89[1])+(val61*val89[2])+(val62*val89[3])+(val63*val90[0])+(val64*val90[1])+(val65*val90[2])+(val66*val90[3])+(val67*val91[0])+(val68*val91[1])+(val69*val91[2])+(val70*val91[3])+(val71*val92[0])+(val72*val92[1])+(val73*val92[2])+(val74*val92[3])+(val75*val93[0])+(val76*val93[1])+(val77*val93[2])+(val78*val93[3]));
                float4 val94 = *((float4*)(data2+alu2+1200));
                float4 val95 = *((float4*)(data2+alu2+1204));
                float4 val96 = *((float4*)(data2+alu2+1208));
                float4 val97 = *((float4*)(data2+alu2+1212));
                float4 val98 = *((float4*)(data2+alu2+1216));
                acc12 = (acc12+(val79*val94[0])+(val0*val94[1])+(val1*val94[2])+(val2*val94[3])+(val3*val95[0])+(val4*val95[1])+(val5*val95[2])+(val6*val95[3])+(val7*val96[0])+(val8*val96[1])+(val9*val96[2])+(val10*val96[3])+(val11*val97[0])+(val12*val97[1])+(val13*val97[2])+(val14*val97[3])+(val15*val98[0])+(val16*val98[1])+(val17*val98[2])+(val18*val98[3]));
                acc13 = (acc13+(val19*val94[0])+(val20*val94[1])+(val21*val94[2])+(val22*val94[3])+(val23*val95[0])+(val24*val95[1])+(val25*val95[2])+(val26*val95[3])+(val27*val96[0])+(val28*val96[1])+(val29*val96[2])+(val30*val96[3])+(val31*val97[0])+(val32*val97[1])+(val33*val97[2])+(val34*val97[3])+(val35*val98[0])+(val36*val98[1])+(val37*val98[2])+(val38*val98[3]));
                acc14 = (acc14+(val39*val94[0])+(val40*val94[1])+(val41*val94[2])+(val42*val94[3])+(val43*val95[0])+(val44*val95[1])+(val45*val95[2])+(val46*val95[3])+(val47*val96[0])+(val48*val96[1])+(val49*val96[2])+(val50*val96[3])+(val51*val97[0])+(val52*val97[1])+(val53*val97[2])+(val54*val97[3])+(val55*val98[0])+(val56*val98[1])+(val57*val98[2])+(val58*val98[3]));
                acc15 = (acc15+(val59*val94[0])+(val60*val94[1])+(val61*val94[2])+(val62*val94[3])+(val63*val95[0])+(val64*val95[1])+(val65*val95[2])+(val66*val95[3])+(val67*val96[0])+(val68*val96[1])+(val69*val96[2])+(val70*val96[3])+(val71*val97[0])+(val72*val97[1])+(val73*val97[2])+(val74*val97[3])+(val75*val98[0])+(val76*val98[1])+(val77*val98[2])+(val78*val98[3]));
                float4 val99 = *((float4*)(data2+alu2));
                acc0 = (acc0+(val79*val99[0])+(val0*val99[1])+(val1*val99[2])+(val2*val99[3])+(val3*val80[0])+(val4*val80[1])+(val5*val80[2])+(val6*val80[3])+(val7*val81[0])+(val8*val81[1])+(val9*val81[2])+(val10*val81[3])+(val11*val82[0])+(val12*val82[1])+(val13*val82[2])+(val14*val82[3])+(val15*val83[0])+(val16*val83[1])+(val17*val83[2])+(val18*val83[3]));
                acc1 = (acc1+(val19*val99[0])+(val20*val99[1])+(val21*val99[2])+(val22*val99[3])+(val23*val80[0])+(val24*val80[1])+(val25*val80[2])+(val26*val80[3])+(val27*val81[0])+(val28*val81[1])+(val29*val81[2])+(val30*val81[3])+(val31*val82[0])+(val32*val82[1])+(val33*val82[2])+(val34*val82[3])+(val35*val83[0])+(val36*val83[1])+(val37*val83[2])+(val38*val83[3]));
                acc2 = (acc2+(val39*val99[0])+(val40*val99[1])+(val41*val99[2])+(val42*val99[3])+(val43*val80[0])+(val44*val80[1])+(val45*val80[2])+(val46*val80[3])+(val47*val81[0])+(val48*val81[1])+(val49*val81[2])+(val50*val81[3])+(val51*val82[0])+(val52*val82[1])+(val53*val82[2])+(val54*val82[3])+(val55*val83[0])+(val56*val83[1])+(val57*val83[2])+(val58*val83[3]));
                acc3 = (acc3+(val59*val99[0])+(val60*val99[1])+(val61*val99[2])+(val62*val99[3])+(val63*val80[0])+(val64*val80[1])+(val65*val80[2])+(val66*val80[3])+(val67*val81[0])+(val68*val81[1])+(val69*val81[2])+(val70*val81[3])+(val71*val82[0])+(val72*val82[1])+(val73*val82[2])+(val74*val82[3])+(val75*val83[0])+(val76*val83[1])+(val77*val83[2])+(val78*val83[3]));
              }
            }
            *(data0+alu0+3200) = acc1;
            *(data0+alu0+6400) = acc2;
            *(data0+alu0+9600) = acc3;
            *(data0+alu0+102400) = acc4;
            *(data0+alu0+105600) = acc5;
            *(data0+alu0+108800) = acc6;
            *(data0+alu0+112000) = acc7;
            *(data0+alu0+204800) = acc8;
            *(data0+alu0+208000) = acc9;
            *(data0+alu0+211200) = acc10;
            *(data0+alu0+214400) = acc11;
            *(data0+alu0+307200) = acc12;
            *(data0+alu0+310400) = acc13;
            *(data0+alu0+313600) = acc14;
            *(data0+alu0+316800) = acc15;
            *(data0+alu0) = acc0;
          }
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_256_2_100_4(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    for (int ridx1 = 0; ridx1 < 256; ridx1++) {
      float acc0 = 0.0f;
      for (int ridx2 = 0; ridx2 < 2; ridx2++) {
        for (int ridx3 = 0; ridx3 < 100; ridx3++) {
          float4 val0 = *((float4*)(data1+(ridx0*400)+(ridx1*25600)+(ridx2*12800)+(ridx3<<2)));
          acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
        }
      }
      *(data0+(ridx0<<8)+ridx1) = acc0;
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_8_4n13(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5) {
  for (int ridx0 = 0; ridx0 < 8; ridx0++) {
    int alu0 = (ridx0<<2);
    float val0 = *(data1+0);
    float val1 = *(data3+0);
    float val2 = *(data5+0);
    float alu1 = (1/val2);
    float4 val3 = *((float4*)(data0+alu0));
    float4 val4 = *((float4*)(data2+alu0));
    float4 val5 = *((float4*)(data4+alu0));
    *((float4*)(data0+alu0)) = (float4){(val3[0]-(val0*val4[0]*(1/(val1*(__builtin_sqrtf((val5[0]*alu1))+1e-08f))))),(val3[1]-(val0*val4[1]*(1/(val1*(__builtin_sqrtf((val5[1]*alu1))+1e-08f))))),(val3[2]-(val0*val4[2]*(1/(val1*(__builtin_sqrtf((val5[2]*alu1))+1e-08f))))),(val3[3]-(val0*val4[3]*(1/(val1*(__builtin_sqrtf((val5[3]*alu1))+1e-08f)))))};
  }
}

void r_512_32_24_8_6_3_6(float* restrict data0, float* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    for (int ridx1 = 0; ridx1 < 32; ridx1++) {
      for (int ridx2 = 0; ridx2 < 24; ridx2++) {
        for (int ridx3 = 0; ridx3 < 8; ridx3++) {
          int alu0 = (ridx3*3);
          int alu1 = (alu0+21);
          int alu2 = (alu0+22);
          int alu3 = (alu0+23);
          int alu4 = (alu0+24);
          int alu5 = (alu1%25);
          int alu6 = (alu2%25);
          int alu7 = (alu3%25);
          int alu8 = (alu4%25);
          int alu9 = ((ridx0*18432)+(ridx1*576)+(ridx2*24)+alu0);
          int alu10 = (alu9+1);
          int alu11 = (alu9+2);
          float acc0 = 0.0f;
          float acc1 = 0.0f;
          float acc2 = 0.0f;
          for (int ridx4 = 0; ridx4 < 6; ridx4++) {
            int alu12 = (ridx2+(ridx4*24));
            int alu13 = (alu12%25);
            int alu14 = ((ridx0*320000)+(ridx1*10000)+((alu12/25)*5)+(alu13*500));
            int alu15 = (alu14+(ridx3*75));
            int alu16 = ((alu2/25)+alu14+(alu6*25));
            int alu17 = ((alu3/25)+alu14+(alu7*25));
            int alu18 = ((alu4/25)+alu14+(alu8*25));
            _Bool alu19 = ((alu12<125)&(alu13<20));
            _Bool alu20 = (alu19&(alu6<20));
            _Bool alu21 = (alu19&(alu7<20));
            _Bool alu22 = (alu19&(alu8<20));
            _Bool alu23 = (alu19&(ridx3<7));
            float val0 = (alu23?*(data2+alu15+1):0.0f);
            float val1 = (alu23?*(data2+alu15+2):0.0f);
            float val2 = (alu23?*(data2+alu15+25):0.0f);
            float val3 = (alu23?*(data2+alu15+26):0.0f);
            float val4 = ((alu19&(ridx3<6))?*(data2+alu15+50):0.0f);
            float val5 = (alu23?*(data2+alu15):0.0f);
            float val6 = ((alu19&(alu5<20))?*(data2+(alu1/25)+alu14+(alu5*25)+3):0.0f);
            float val7 = (alu20?*(data2+alu16+2):0.0f);
            float val8 = (alu20?*(data2+alu16+3):0.0f);
            float val9 = (alu21?*(data2+alu17+1):0.0f);
            float val10 = (alu21?*(data2+alu17+2):0.0f);
            float val11 = (alu21?*(data2+alu17+3):0.0f);
            float val12 = (alu22?*(data2+alu18+1):0.0f);
            acc1 = (acc1+val2+val0+val12+val10+val8);
            float val13 = (alu22?*(data2+alu18+2):0.0f);
            acc2 = (acc2+val4+val3+val1+val13+val11);
            float val14 = (alu22?*(data2+alu18):0.0f);
            acc0 = (acc0+val5+val14+val9+val7+val6);
          }
          float val15 = *(data1+alu10);
          *(data0+alu10) = ((float)((0.0f<val15))*acc1);
          float val16 = *(data1+alu11);
          *(data0+alu11) = ((float)((0.0f<val16))*acc2);
          float val17 = *(data1+alu9);
          *(data0+alu9) = ((float)((0.0f<val17))*acc0);
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r3_6400_32_4_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 6400; ridx0++) {
    int alu0 = (ridx0<<2);
    float acc0 = 0.0f;
    float acc1 = 0.0f;
    float acc2 = 0.0f;
    float acc3 = 0.0f;
    for (int ridx1 = 0; ridx1 < 32; ridx1++) {
      int alu1 = ((ridx0<<9)+(ridx1<<2));
      float4 val0 = *((float4*)(data1+alu1+128));
      acc1 = (acc1+val0[0]+val0[1]+val0[2]+val0[3]);
      float4 val1 = *((float4*)(data1+alu1+256));
      acc2 = (acc2+val1[0]+val1[1]+val1[2]+val1[3]);
      float4 val2 = *((float4*)(data1+alu1+384));
      acc3 = (acc3+val2[0]+val2[1]+val2[2]+val2[3]);
      float4 val3 = *((float4*)(data1+alu1));
      acc0 = (acc0+val3[0]+val3[1]+val3[2]+val3[3]);
    }
    float val4 = *(data4+0);
    float val5 = *(data5+0);
    float val6 = *(data6+0);
    float alu2 = (1/val6);
    float4 val7 = *((float4*)(data0+alu0));
    float alu3 = ((val7[0]*0.9f)+(acc0*0.09999999999999998f));
    float alu4 = ((val7[1]*0.9f)+(acc1*0.09999999999999998f));
    float alu5 = ((val7[2]*0.9f)+(acc2*0.09999999999999998f));
    float alu6 = ((val7[3]*0.9f)+(acc3*0.09999999999999998f));
    *((float4*)(data0+alu0)) = (float4){alu3,alu4,alu5,alu6};
    float4 val8 = *((float4*)(data2+alu0));
    float alu7 = ((val8[0]*0.999f)+(acc0*acc0*0.0010000000000000009f));
    float alu8 = ((val8[1]*0.999f)+(acc1*acc1*0.0010000000000000009f));
    float alu9 = ((val8[2]*0.999f)+(acc2*acc2*0.0010000000000000009f));
    float alu10 = ((val8[3]*0.999f)+(acc3*acc3*0.0010000000000000009f));
    *((float4*)(data2+alu0)) = (float4){alu7,alu8,alu9,alu10};
    float4 val9 = *((float4*)(data3+alu0));
    *((float4*)(data3+alu0)) = (float4){(val9[0]-(val4*alu3*(1/(val5*(__builtin_sqrtf((alu7*alu2))+1e-08f))))),(val9[1]-(val4*alu4*(1/(val5*(__builtin_sqrtf((alu8*alu2))+1e-08f))))),(val9[2]-(val4*alu5*(1/(val5*(__builtin_sqrtf((alu9*alu2))+1e-08f))))),(val9[3]-(val4*alu6*(1/(val5*(__builtin_sqrtf((alu10*alu2))+1e-08f)))))};
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r3_32_64_4n3(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float4 val0 = *((float4*)(data1+(ridx0<<8)+(ridx1<<2)));
      acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
    }
    float val1 = *(data0+ridx0);
    float alu0 = ((val1*0.9f)+(acc0*0.09999999999999998f));
    *(data0+ridx0) = alu0;
    float val2 = *(data2+ridx0);
    float alu1 = ((val2*0.999f)+(acc0*acc0*0.0010000000000000009f));
    *(data2+ridx0) = alu1;
    float val3 = *(data3+ridx0);
    float val4 = *(data4+0);
    float val5 = *(data5+0);
    float val6 = *(data6+0);
    *(data3+ridx0) = (val3-(val4*alu0*(1/(val5*(__builtin_sqrtf((alu1*(1/val6)))+1e-08f)))));
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_8_5_5_256_2_24_4_24(float* restrict data0, unsigned char* restrict data1, float* restrict data2) {
  for (int ridx0 = 0; ridx0 < 8; ridx0++) {
    for (int ridx1 = 0; ridx1 < 5; ridx1++) {
      for (int ridx2 = 0; ridx2 < 5; ridx2++) {
        for (int ridx3 = 0; ridx3 < 256; ridx3++) {
          int alu0 = ((ridx0*25600)+(ridx1*1280)+(ridx2<<8)+ridx3);
          float acc0 = 0.0f;
          float acc1 = 0.0f;
          float acc2 = 0.0f;
          float acc3 = 0.0f;
          for (int ridx4 = 0; ridx4 < 2; ridx4++) {
            for (int ridx5 = 0; ridx5 < 24; ridx5++) {
              int alu1 = ((ridx1*28)+ridx2+(ridx3*1568)+(ridx4*784)+(ridx5*28));
              int alu2 = ((ridx0*2304)+(ridx3*36864)+(ridx4*18432)+(ridx5*24));
              unsigned char val0 = *(data1+alu1+1);
              float cast0 = (float)(val0);
              unsigned char val1 = *(data1+alu1+2);
              float cast1 = (float)(val1);
              unsigned char val2 = *(data1+alu1+3);
              float cast2 = (float)(val2);
              unsigned char val3 = *(data1+alu1+4);
              float cast3 = (float)(val3);
              unsigned char val4 = *(data1+alu1+5);
              float cast4 = (float)(val4);
              unsigned char val5 = *(data1+alu1+6);
              float cast5 = (float)(val5);
              unsigned char val6 = *(data1+alu1+7);
              float cast6 = (float)(val6);
              unsigned char val7 = *(data1+alu1+8);
              float cast7 = (float)(val7);
              unsigned char val8 = *(data1+alu1+9);
              float cast8 = (float)(val8);
              unsigned char val9 = *(data1+alu1+10);
              float cast9 = (float)(val9);
              unsigned char val10 = *(data1+alu1+11);
              float cast10 = (float)(val10);
              unsigned char val11 = *(data1+alu1+12);
              float cast11 = (float)(val11);
              unsigned char val12 = *(data1+alu1+13);
              float cast12 = (float)(val12);
              unsigned char val13 = *(data1+alu1+14);
              float cast13 = (float)(val13);
              unsigned char val14 = *(data1+alu1+15);
              float cast14 = (float)(val14);
              unsigned char val15 = *(data1+alu1+16);
              float cast15 = (float)(val15);
              unsigned char val16 = *(data1+alu1+17);
              float cast16 = (float)(val16);
              unsigned char val17 = *(data1+alu1+18);
              float cast17 = (float)(val17);
              unsigned char val18 = *(data1+alu1+19);
              float cast18 = (float)(val18);
              unsigned char val19 = *(data1+alu1+20);
              float cast19 = (float)(val19);
              unsigned char val20 = *(data1+alu1+21);
              float cast20 = (float)(val20);
              unsigned char val21 = *(data1+alu1+22);
              float cast21 = (float)(val21);
              unsigned char val22 = *(data1+alu1+23);
              float cast22 = (float)(val22);
              unsigned char val23 = *(data1+alu1);
              float cast23 = (float)(val23);
              float4 val24 = *((float4*)(data2+alu2+4));
              float4 val25 = *((float4*)(data2+alu2+8));
              float4 val26 = *((float4*)(data2+alu2+12));
              float4 val27 = *((float4*)(data2+alu2+16));
              float4 val28 = *((float4*)(data2+alu2+20));
              float4 val29 = *((float4*)(data2+alu2+576));
              float4 val30 = *((float4*)(data2+alu2+580));
              float4 val31 = *((float4*)(data2+alu2+584));
              float4 val32 = *((float4*)(data2+alu2+588));
              float4 val33 = *((float4*)(data2+alu2+592));
              float4 val34 = *((float4*)(data2+alu2+596));
              acc1 = (acc1+(cast23*val29[0])+(cast0*val29[1])+(cast1*val29[2])+(cast2*val29[3])+(cast3*val30[0])+(cast4*val30[1])+(cast5*val30[2])+(cast6*val30[3])+(cast7*val31[0])+(cast8*val31[1])+(cast9*val31[2])+(cast10*val31[3])+(cast11*val32[0])+(cast12*val32[1])+(cast13*val32[2])+(cast14*val32[3])+(cast15*val33[0])+(cast16*val33[1])+(cast17*val33[2])+(cast18*val33[3])+(cast19*val34[0])+(cast20*val34[1])+(cast21*val34[2])+(cast22*val34[3]));
              float4 val35 = *((float4*)(data2+alu2+1152));
              float4 val36 = *((float4*)(data2+alu2+1156));
              float4 val37 = *((float4*)(data2+alu2+1160));
              float4 val38 = *((float4*)(data2+alu2+1164));
              float4 val39 = *((float4*)(data2+alu2+1168));
              float4 val40 = *((float4*)(data2+alu2+1172));
              acc2 = (acc2+(cast23*val35[0])+(cast0*val35[1])+(cast1*val35[2])+(cast2*val35[3])+(cast3*val36[0])+(cast4*val36[1])+(cast5*val36[2])+(cast6*val36[3])+(cast7*val37[0])+(cast8*val37[1])+(cast9*val37[2])+(cast10*val37[3])+(cast11*val38[0])+(cast12*val38[1])+(cast13*val38[2])+(cast14*val38[3])+(cast15*val39[0])+(cast16*val39[1])+(cast17*val39[2])+(cast18*val39[3])+(cast19*val40[0])+(cast20*val40[1])+(cast21*val40[2])+(cast22*val40[3]));
              float4 val41 = *((float4*)(data2+alu2+1728));
              float4 val42 = *((float4*)(data2+alu2+1732));
              float4 val43 = *((float4*)(data2+alu2+1736));
              float4 val44 = *((float4*)(data2+alu2+1740));
              float4 val45 = *((float4*)(data2+alu2+1744));
              float4 val46 = *((float4*)(data2+alu2+1748));
              acc3 = (acc3+(cast23*val41[0])+(cast0*val41[1])+(cast1*val41[2])+(cast2*val41[3])+(cast3*val42[0])+(cast4*val42[1])+(cast5*val42[2])+(cast6*val42[3])+(cast7*val43[0])+(cast8*val43[1])+(cast9*val43[2])+(cast10*val43[3])+(cast11*val44[0])+(cast12*val44[1])+(cast13*val44[2])+(cast14*val44[3])+(cast15*val45[0])+(cast16*val45[1])+(cast17*val45[2])+(cast18*val45[3])+(cast19*val46[0])+(cast20*val46[1])+(cast21*val46[2])+(cast22*val46[3]));
              float4 val47 = *((float4*)(data2+alu2));
              acc0 = (acc0+(cast23*val47[0])+(cast0*val47[1])+(cast1*val47[2])+(cast2*val47[3])+(cast3*val24[0])+(cast4*val24[1])+(cast5*val24[2])+(cast6*val24[3])+(cast7*val25[0])+(cast8*val25[1])+(cast9*val25[2])+(cast10*val25[3])+(cast11*val26[0])+(cast12*val26[1])+(cast13*val26[2])+(cast14*val26[3])+(cast15*val27[0])+(cast16*val27[1])+(cast17*val27[2])+(cast18*val27[3])+(cast19*val28[0])+(cast20*val28[1])+(cast21*val28[2])+(cast22*val28[3]));
            }
          }
          *(data0+alu0+6400) = acc1;
          *(data0+alu0+12800) = acc2;
          *(data0+alu0+19200) = acc3;
          *(data0+alu0) = acc0;
        }
      }
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_32_256_2_144_4(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 32; ridx0++) {
    for (int ridx1 = 0; ridx1 < 256; ridx1++) {
      float acc0 = 0.0f;
      for (int ridx2 = 0; ridx2 < 2; ridx2++) {
        for (int ridx3 = 0; ridx3 < 144; ridx3++) {
          float4 val0 = *((float4*)(data1+(ridx0*576)+(ridx1*36864)+(ridx2*18432)+(ridx3<<2)));
          acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
        }
      }
      *(data0+(ridx0<<8)+ridx1) = acc0;
    }
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r3_800_64_4n1(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, float* restrict data4, float* restrict data5, float* restrict data6) {
  for (int ridx0 = 0; ridx0 < 800; ridx0++) {
    float acc0 = 0.0f;
    for (int ridx1 = 0; ridx1 < 64; ridx1++) {
      float4 val0 = *((float4*)(data1+(ridx0<<8)+(ridx1<<2)));
      acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
    }
    float val1 = *(data0+ridx0);
    float alu0 = ((val1*0.9f)+(acc0*0.09999999999999998f));
    *(data0+ridx0) = alu0;
    float val2 = *(data2+ridx0);
    float alu1 = ((val2*0.999f)+(acc0*acc0*0.0010000000000000009f));
    *(data2+ridx0) = alu1;
    float val3 = *(data3+ridx0);
    float val4 = *(data4+0);
    float val5 = *(data5+0);
    float val6 = *(data6+0);
    *(data3+ridx0) = (val3-(val4*alu0*(1/(val5*(__builtin_sqrtf((alu1*(1/val6)))+1e-08f)))));
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void E_128_4n3(float* restrict data0, float* restrict data1) {
  for (int ridx0 = 0; ridx0 < 128; ridx0++) {
    int alu0 = (ridx0<<2);
    float4 val0 = *((float4*)(data1+alu0));
    _Bool alu1 = (val0[0]<0.0001f);
    _Bool alu2 = (val0[1]<0.0001f);
    _Bool alu3 = (val0[2]<0.0001f);
    _Bool alu4 = (val0[3]<0.0001f);
    _Bool alu5 = (val0[0]!=__builtin_inff());
    _Bool alu6 = (val0[1]!=__builtin_inff());
    _Bool alu7 = (val0[2]!=__builtin_inff());
    _Bool alu8 = (val0[3]!=__builtin_inff());
    float alu9 = (alu1?(val0[0]*256.0f):val0[0]);
    float alu10 = (alu1?(alu9*256.0f):alu9);
    float alu11 = (alu1?(alu10*256.0f):alu10);
    float alu12 = (alu1?(alu11*256.0f):alu11);
    float alu13 = (alu1?(alu12*256.0f):alu12);
    float alu14 = (alu1?(alu13*256.0f):alu13);
    float alu15 = (alu1?(alu14*256.0f):alu14);
    float alu16 = (alu1?(alu15*256.0f):alu15);
    float precast0 = alu16;
    float precast1 = (alu16*1.3333333333333333f);
    float cast0 = (float)(((((*((int*)&precast1))>>23)&255)+-127));
    int precast2 = ((*((int*)&precast0))+((int)(-cast0)<<23));
    float cast1 = (*((float*)&precast2));
    float alu17 = ((cast1+-1.0f)*(1/(cast1+1.0f)));
    float alu18 = (alu17*alu17);
    float alu19 = (alu2?(val0[1]*256.0f):val0[1]);
    float alu20 = (alu2?(alu19*256.0f):alu19);
    float alu21 = (alu2?(alu20*256.0f):alu20);
    float alu22 = (alu2?(alu21*256.0f):alu21);
    float alu23 = (alu2?(alu22*256.0f):alu22);
    float alu24 = (alu2?(alu23*256.0f):alu23);
    float alu25 = (alu2?(alu24*256.0f):alu24);
    float alu26 = (alu2?(alu25*256.0f):alu25);
    float precast3 = alu26;
    float precast4 = (alu26*1.3333333333333333f);
    float cast2 = (float)(((((*((int*)&precast4))>>23)&255)+-127));
    int precast5 = ((*((int*)&precast3))+((int)(-cast2)<<23));
    float cast3 = (*((float*)&precast5));
    float alu27 = ((cast3+-1.0f)*(1/(cast3+1.0f)));
    float alu28 = (alu27*alu27);
    float alu29 = (alu3?(val0[2]*256.0f):val0[2]);
    float alu30 = (alu3?(alu29*256.0f):alu29);
    float alu31 = (alu3?(alu30*256.0f):alu30);
    float alu32 = (alu3?(alu31*256.0f):alu31);
    float alu33 = (alu3?(alu32*256.0f):alu32);
    float alu34 = (alu3?(alu33*256.0f):alu33);
    float alu35 = (alu3?(alu34*256.0f):alu34);
    float alu36 = (alu3?(alu35*256.0f):alu35);
    float precast6 = alu36;
    float precast7 = (alu36*1.3333333333333333f);
    float cast4 = (float)(((((*((int*)&precast7))>>23)&255)+-127));
    int precast8 = ((*((int*)&precast6))+((int)(-cast4)<<23));
    float cast5 = (*((float*)&precast8));
    float alu37 = ((cast5+-1.0f)*(1/(cast5+1.0f)));
    float alu38 = (alu37*alu37);
    float alu39 = (alu4?(val0[3]*256.0f):val0[3]);
    float alu40 = (alu4?(alu39*256.0f):alu39);
    float alu41 = (alu4?(alu40*256.0f):alu40);
    float alu42 = (alu4?(alu41*256.0f):alu41);
    float alu43 = (alu4?(alu42*256.0f):alu42);
    float alu44 = (alu4?(alu43*256.0f):alu43);
    float alu45 = (alu4?(alu44*256.0f):alu44);
    float alu46 = (alu4?(alu45*256.0f):alu45);
    float precast9 = alu46;
    float precast10 = (alu46*1.3333333333333333f);
    float cast6 = (float)(((((*((int*)&precast10))>>23)&255)+-127));
    int precast11 = ((*((int*)&precast9))+((int)(-cast6)<<23));
    float cast7 = (*((float*)&precast11));
    float alu47 = ((cast7+-1.0f)*(1/(cast7+1.0f)));
    float alu48 = (alu47*alu47);
    float alu49 = ((val0[0]<0.0f)?__builtin_nanf(""):(alu5?((alu1?(cast0+-64.0f):cast0)+(alu17*2.885390043258667f)+(alu17*3.273447448356849e-08f)+(alu18*alu17*((((alu18*0.4374550283f)+0.5764790177f)*alu18)+0.961801290512f))):__builtin_inff()));
    float alu50 = ((val0[1]<0.0f)?__builtin_nanf(""):(alu6?((alu2?(cast2+-64.0f):cast2)+(alu27*2.885390043258667f)+(alu27*3.273447448356849e-08f)+(alu28*alu27*((((alu28*0.4374550283f)+0.5764790177f)*alu28)+0.961801290512f))):__builtin_inff()));
    float alu51 = ((val0[2]<0.0f)?__builtin_nanf(""):(alu7?((alu3?(cast4+-64.0f):cast4)+(alu37*2.885390043258667f)+(alu37*3.273447448356849e-08f)+(alu38*alu37*((((alu38*0.4374550283f)+0.5764790177f)*alu38)+0.961801290512f))):__builtin_inff()));
    float alu52 = ((val0[3]<0.0f)?__builtin_nanf(""):(alu8?((alu4?(cast6+-64.0f):cast6)+(alu47*2.885390043258667f)+(alu47*3.273447448356849e-08f)+(alu48*alu47*((((alu48*0.4374550283f)+0.5764790177f)*alu48)+0.961801290512f))):__builtin_inff()));
    *((float4*)(data0+alu0)) = (float4){((((1/val0[0])!=-__builtin_inff())?((val0[0]<__builtin_inff())?((alu49!=-191.0f)?alu49:-__builtin_inff()):(alu5?__builtin_nanf(""):alu16)):-__builtin_inff())*0.6931471805599453f),((((1/val0[1])!=-__builtin_inff())?((val0[1]<__builtin_inff())?((alu50!=-191.0f)?alu50:-__builtin_inff()):(alu6?__builtin_nanf(""):alu26)):-__builtin_inff())*0.6931471805599453f),((((1/val0[2])!=-__builtin_inff())?((val0[2]<__builtin_inff())?((alu51!=-191.0f)?alu51:-__builtin_inff()):(alu7?__builtin_nanf(""):alu36)):-__builtin_inff())*0.6931471805599453f),((((1/val0[3])!=-__builtin_inff())?((val0[3]<__builtin_inff())?((alu52!=-191.0f)?alu52:-__builtin_inff()):(alu8?__builtin_nanf(""):alu46)):-__builtin_inff())*0.6931471805599453f)};
  }
}
typedef float float2 __attribute__((aligned(8),vector_size(8)));
void r_512_10n3(float* restrict data0, float* restrict data1, float* restrict data2, float* restrict data3, int* restrict data4, int* restrict data5) {
  for (int ridx0 = 0; ridx0 < 512; ridx0++) {
    int alu0 = (ridx0*10);
    int val0 = *(data4+0);
    int val1 = *(data4+1);
    int val2 = *(data4+2);
    int val3 = *(data4+3);
    int val4 = *(data4+4);
    int val5 = *(data4+5);
    int val6 = *(data4+6);
    int val7 = *(data4+7);
    int val8 = *(data4+8);
    int val9 = *(data4+9);
    int val10 = *(data5+ridx0);
    float val11 = *(data2+ridx0);
    float val12 = *(data3+ridx0);
    float2 val13 = *((float2*)(data1+alu0+2));
    float2 val14 = *((float2*)(data1+alu0+4));
    float2 val15 = *((float2*)(data1+alu0+6));
    float2 val16 = *((float2*)(data1+alu0+8));
    float2 val17 = *((float2*)(data1+alu0));
    *(data0+ridx0) = ((((val17[0]-val11)-val12)*(float)(((val0!=val10)!=1)))+(((val17[1]-val11)-val12)*(float)(((val1!=val10)!=1)))+(((val13[0]-val11)-val12)*(float)(((val2!=val10)!=1)))+(((val13[1]-val11)-val12)*(float)(((val3!=val10)!=1)))+(((val14[0]-val11)-val12)*(float)(((val4!=val10)!=1)))+(((val14[1]-val11)-val12)*(float)(((val5!=val10)!=1)))+(((val15[0]-val11)-val12)*(float)(((val6!=val10)!=1)))+(((val15[1]-val11)-val12)*(float)(((val7!=val10)!=1)))+(((val16[0]-val11)-val12)*(float)(((val8!=val10)!=1)))+(((val16[1]-val11)-val12)*(float)(((val9!=val10)!=1))));
  }
}
typedef float float4 __attribute__((aligned(16),vector_size(16)));
void r_128_4(float* restrict data0, float* restrict data1) {
  float acc0 = 0.0f;
  for (int ridx0 = 0; ridx0 < 128; ridx0++) {
    float4 val0 = *((float4*)(data1+(ridx0<<2)));
    acc0 = (acc0+val0[0]+val0[1]+val0[2]+val0[3]);
  }
  *(data0+0) = (acc0*-0.001953125f);
}
void batched() {
  r_64_512_9_4n1((float*)0x5D53858207A0,(float*)0x7E2060400010,(float*)0x5D5385941760);
  E_16_4n9((float*)0x7E20561E5E30,(float*)0x5D53858207A0);
  E_16_4n7((float*)0x7E20561E5830,(float*)0x5D53858207A0);
  r_512_64_3_3_2_2n2((float*)0x5D53855AF350,(float*)0x7E2060400010,(float*)0x5D5385941760,(float*)0x7E2056131730,(float*)0x7E20561E5830,(float*)0x7E2056133630);
  r_512_64_3_3_2_2n3((float*)0x7E2057000010,(float*)0x7E2060400010,(float*)0x5D5385941760,(float*)0x7E2056131730,(float*)0x7E20561E5830,(float*)0x7E2056133630,(float*)0x5D53855AF350);
  r_128_10_144_4_4((float*)0x5D5384CAB360,(float*)0x5D53855AF350,(float*)0x5D53852F67A0,(float*)0x7E20991AA6A0);
  r_512_10((float*)0x5D5384EDA150,(float*)0x5D5384CAB360);
  r_512_10n1((float*)0x5D5384F95210,(float*)0x5D5384CAB360,(float*)0x5D5384EDA150);
  r_512_10n2((float*)0x7E2055A00010,(int*)0x7E209915BA20,(int*)0x5D5384BA8990,(float*)0x5D5384F95210);
  E_128_10_4((float*)0x5D538527BC70,(int*)0x7E209915BA20,(int*)0x5D5384BA8990,(float*)0x5D5384CAB360,(float*)0x5D5384EDA150,(float*)0x7E2055A00010);
  r3_10_128_4n1((float*)0x7E20991AA2B0,(float*)0x5D538527BC70,(float*)0x7E20991AA2E0,(float*)0x7E20991AA6A0,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r_128_192_4_3_10((float*)0x7E2055A00010,(float*)0x5D53852F67A0,(float*)0x5D538527BC70);
  r_64_512_6_6n2((float*)0x7E20561E6830,(float*)0x7E2060400010,(float*)0x5D5385941760,(float*)0x7E2056131730,(float*)0x7E20561E5830,(float*)0x7E2056133630,(float*)0x5D53855AF350,(float*)0x7E2057000010,(float*)0x7E2055A00010,(float*)0x5D53858207A0);
  r3_10_192_128_3_4n1((float*)0x5D5384BCC050,(float*)0x5D53855AF350,(float*)0x5D538527BC70,(float*)0x5D5385507B10,(float*)0x5D53852F67A0,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r_64_512_6_6n3((float*)0x5D53858207A0,(float*)0x7E2056131730,(float*)0x7E20561E5830,(float*)0x7E2060400010,(float*)0x5D5385941760,(float*)0x7E2056133630,(float*)0x5D53855AF350,(float*)0x7E2057000010,(float*)0x7E2055A00010);
  r_64_512_6_6n4((float*)0x7E208ACE0B30,(float*)0x7E2060400010,(float*)0x5D5385941760,(float*)0x7E20561E5830,(float*)0x7E2056131730,(float*)0x7E2056133630,(float*)0x5D53855AF350,(float*)0x7E2057000010,(float*)0x7E2055A00010);
  r_64_512_6_6n5((float*)0x7E205D548C30,(float*)0x7E2060400010,(float*)0x5D5385941760,(float*)0x7E2056131730,(float*)0x7E20561E5830,(float*)0x7E2056133630,(float*)0x5D53855AF350,(float*)0x7E2057000010,(float*)0x7E2055A00010);
  E_512_64_6_2_3n1((float*)0x7E2054A00010,(float*)0x7E2060400010,(float*)0x5D5385941760,(float*)0x7E20561E6830,(float*)0x7E2056131730,(float*)0x7E20561E5830,(float*)0x7E2056133630,(float*)0x5D53855AF350,(float*)0x7E2057000010,(float*)0x7E2055A00010,(float*)0x5D53858207A0);
  E_16_4n10((float*)0x7E2056131830,(float*)0x7E208ACE0B30);
  E_16_4n11((float*)0x7E2056131630,(float*)0x7E208ACE0B30);
  E_16_4n10((float*)0x7E2056133E30,(float*)0x7E205D548C30);
  E_16_4n11((float*)0x7E2056133730,(float*)0x7E205D548C30);
  r3_64_512_9_4n1((float*)0x7E20561E5B30,(float*)0x7E2054A00010,(float*)0x7E2056E36C30,(float*)0x7E2056E36D30,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r_512_64_12_3_16_3_3_4((float*)0x7E2060400010,(float*)0x5D5384B6B8A0,(float*)0x7E2054A00010);
  E_16_4n12((float*)0x7E2056131730,(float*)0x7E209B4391A0,(float*)0x7E2056131830,(float*)0x7E209B3BAD20,(float*)0x7E2056131630,(float*)0x7E209B4733A0);
  E_16_4n12((float*)0x7E2056133630,(float*)0x7E209B4391A0,(float*)0x7E2056133E30,(float*)0x7E209B3BAD20,(float*)0x7E2056133730,(float*)0x7E209B4733A0);
  r_512_64_8_2_4_4_4((float*)0x7E2057000010,(float*)0x7E2055000010,(float*)0x7E2060400010);
  r3_16_64_3_512_6_4_3_6n1((float*)0x5D5384F2FAA0,(float*)0x7E2055000010,(float*)0x7E2054A00010,(float*)0x5D5384F06F40,(float*)0x5D5384B6B8A0,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r_512_32_16_3_16_4_3_4((float*)0x7E2060400010,(float*)0x5D538547F870,(float*)0x7E2057000010);
  r_16_32_3_128_4_8_4_3_8((float*)0x7E2053A00010,(float*)0x7E208A400010,(float*)0x7E2057000010);
  r_64_256_2_16_4((float*)0x5D5384CD0DE0,(float*)0x7E2057000010);
  r_512_32_10_10_4_4((float*)0x7E2055A00010,(float*)0x7E2060400010);
  r3_6144_32_3_4n1((float*)0x5D5384B02090,(float*)0x7E2053A00010,(float*)0x5D5384E28EB0,(float*)0x5D538547F870,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r3_64_64_4n1((float*)0x7E208ACE3C30,(float*)0x5D5384CD0DE0,(float*)0x7E2056E6FA30,(float*)0x7E2056E6F930,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r_32_64_2_20_4_20n4((float*)0x7E2060400010,(float*)0x7E205B000010,(float*)0x7E209B4734B0,(float*)0x7E205615B1B0,(float*)0x7E20549B70B0,(float*)0x7E2054F2A9B0,(float*)0x7E208A400010,(float*)0x7E2056200010,(float*)0x7E2055A00010);
  r_32_64_2_20_4_20n5((float*)0x7E2057000010,(float*)0x7E205615B1B0,(float*)0x7E20549B70B0,(float*)0x7E205B000010,(float*)0x7E209B4734B0,(float*)0x7E2054F2A9B0,(float*)0x7E208A400010,(float*)0x7E2056200010,(float*)0x7E2055A00010);
  r_32_64_2_20_4_20n6((float*)0x5D5385941760,(float*)0x7E205B000010,(float*)0x7E209B4734B0,(float*)0x7E20549B70B0,(float*)0x7E205615B1B0,(float*)0x7E2054F2A9B0,(float*)0x7E208A400010,(float*)0x7E2056200010,(float*)0x7E2055A00010);
  r_32_64_2_20_4_20n7((float*)0x5D53858207A0,(float*)0x7E205B000010,(float*)0x7E209B4734B0,(float*)0x7E205615B1B0,(float*)0x7E20549B70B0,(float*)0x7E2054F2A9B0,(float*)0x7E208A400010,(float*)0x7E2056200010,(float*)0x7E2055A00010);
  r_32_64_4n2((float*)0x7E20561E5830,(float*)0x7E2060400010,(float*)0x7E20549B70B0,(float*)0x7E2099194030);
  r_32_64_4((float*)0x7E2060400010,(float*)0x7E2057000010);
  r_32_64_4n1((float*)0x7E208AC41DB0,(float*)0x5D5385941760);
  r_32_64_4n1((float*)0x7E20991B4EB0,(float*)0x5D53858207A0);
  E_512_32_20_5_4n1((float*)0x7E2057000010,(float*)0x7E205B000010,(float*)0x7E209B4734B0,(float*)0x7E20561E5830,(float*)0x7E205615B1B0,(float*)0x7E20549B70B0,(float*)0x7E2054F2A9B0,(float*)0x7E208A400010,(float*)0x7E2056200010,(float*)0x7E2055A00010,(float*)0x7E2060400010);
  E_8_4n11((float*)0x7E2056EDD2B0,(float*)0x7E208AC41DB0);
  E_8_4n12((float*)0x7E205612F830,(float*)0x7E208AC41DB0);
  E_8_4n11((float*)0x7E2054F2B3B0,(float*)0x7E20991B4EB0);
  E_8_4n12((float*)0x7E2054F2B6B0,(float*)0x7E20991B4EB0);
  r_512_8_100_25_4_4_32((float*)0x7E2060400010,(float*)0x5D5385498B60,(float*)0x7E2057000010);
  r_8_8_5_5_128_4_20_4_4_20((float*)0x7E2052600010,(float*)0x7E2058A00010,(float*)0x7E2057000010);
  r_32_256_2_100_4((float*)0x5D538509C700,(float*)0x7E2057000010);
  E_8_4n13((float*)0x7E205615B1B0,(float*)0x7E209B4391A0,(float*)0x7E2056EDD2B0,(float*)0x7E209B3BAD20,(float*)0x7E205612F830,(float*)0x7E209B4733A0);
  E_8_4n13((float*)0x7E2054F2A9B0,(float*)0x7E209B4391A0,(float*)0x7E2054F2B3B0,(float*)0x7E209B3BAD20,(float*)0x7E2054F2B6B0,(float*)0x7E209B4733A0);
  r_512_32_24_8_6_3_6((float*)0x7E205B000010,(float*)0x7E2058A00010,(float*)0x7E2060400010);
  r3_6400_32_4_4n1((float*)0x5D5384F97100,(float*)0x7E2052600010,(float*)0x5D53854B5920,(float*)0x5D5385498B60,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r3_32_64_4n3((float*)0x7E209B43B430,(float*)0x5D538509C700,(float*)0x7E2056EDD6B0,(float*)0x7E20549CD630,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r_8_5_5_256_2_24_4_24((float*)0x5D5385949770,(unsigned char*)0x5D5384FB35A0,(float*)0x7E205B000010);
  r_32_256_2_144_4((float*)0x5D5385223FF0,(float*)0x7E205B000010);
  r3_800_64_4n1((float*)0x5D5385569B50,(float*)0x5D5385949770,(float*)0x5D5385019070,(float*)0x5D5385298F20,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  r3_32_64_4n3((float*)0x7E209B439DB0,(float*)0x5D5385223FF0,(float*)0x7E20561581B0,(float*)0x7E205615A130,(float*)0x7E209B4391A0,(float*)0x7E209B3BAD20,(float*)0x7E209B4733A0);
  E_128_4n3((float*)0x7E2060400010,(float*)0x5D5384F95210);
  r_512_10n3((float*)0x7E2058A00010,(float*)0x5D5384CAB360,(float*)0x5D5384EDA150,(float*)0x7E2060400010,(int*)0x7E209915BA20,(int*)0x5D5384BA8990);
  r_128_4((float*)0x7E209B3BA6A0,(float*)0x7E2058A00010);
}