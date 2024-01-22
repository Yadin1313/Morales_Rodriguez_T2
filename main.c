{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red184\green41\blue232;\red26\green28\blue34;\red203\green194\blue208;
\red135\green221\blue95;\red254\green227\blue91;\red231\green70\blue52;\red238\green138\blue18;\red143\green144\blue150;
\red30\green230\blue186;}
{\*\expandedcolortbl;;\cssrgb\c78039\c30196\c92941;\cssrgb\c13725\c14902\c18039;\cssrgb\c83529\c80784\c85098;
\cssrgb\c58824\c87843\c44706;\cssrgb\c100000\c90196\c42745;\cssrgb\c93333\c36471\c26275;\cssrgb\c95294\c61176\c7059;\cssrgb\c62745\c63137\c65490;
\cssrgb\c0\c90980\c77647;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include\cf4 \strokec4  \cf5 \strokec5 <stdint.h>\cf4 \cb1 \strokec4 \
\
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 SIM_5\cf4 \strokec4     (\cf7 \strokec7 *\cf4 \strokec4 ((\cf2 \strokec2 volatile\cf4 \strokec4  \cf2 \strokec2 uint32_t\cf7 \strokec7 *\cf4 \strokec4 )\cf2 \strokec2 0x\cf8 \strokec8 40048038\cf4 \strokec4 ))\cb1 \
\
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 PCR_PTB22\cf4 \strokec4  (\cf7 \strokec7 *\cf4 \strokec4 ((\cf2 \strokec2 volatile\cf4 \strokec4  \cf2 \strokec2 uint32_t\cf7 \strokec7 *\cf4 \strokec4 )\cf2 \strokec2 0x\cf8 \strokec8 4004A058\cf4 \strokec4 ))\cf9 \strokec9 //manipula al PTB22 4004A058\cf4 \cb1 \strokec4 \
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 PCR_PTB21\cf4 \strokec4  (\cf7 \strokec7 *\cf4 \strokec4 ((\cf2 \strokec2 volatile\cf4 \strokec4  \cf2 \strokec2 uint32_t\cf7 \strokec7 *\cf4 \strokec4 )\cf2 \strokec2 0x\cf8 \strokec8 4004A054\cf4 \strokec4 ))\cf9 \strokec9 //manipula al PTB21 4004A054\cf4 \cb1 \strokec4 \
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 PCR_PTE26\cf4 \strokec4  (\cf7 \strokec7 *\cf4 \strokec4 ((\cf2 \strokec2 volatile\cf4 \strokec4  \cf2 \strokec2 uint32_t\cf7 \strokec7 *\cf4 \strokec4 )\cf2 \strokec2 0x\cf8 \strokec8 4004D068\cf4 \strokec4 ))\cf9 \strokec9 //manipula al PTE26 primer cambio\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf9 \cb3 \strokec9 //REGISTROS GPIO\cf4 \cb1 \strokec4 \
\cf9 \cb3 \strokec9 // sirve para el GPIO del puerto B 21 y 22 y para E 26\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 GPIO_B_BASE_ADDR\cf4 \strokec4  (((\cf2 \strokec2 volatile\cf4 \strokec4  \cf2 \strokec2 uint32_t\cf7 \strokec7 *\cf4 \strokec4 )\cf2 \strokec2 0x\cf8 \strokec8 400FF040\cf4 \strokec4 ))\cb1 \
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 GPIO_E_BASE_ADDR\cf4 \strokec4  (((\cf2 \strokec2 volatile\cf4 \strokec4  \cf2 \strokec2 uint32_t\cf7 \strokec7 *\cf4 \strokec4 )\cf2 \strokec2 0x\cf8 \strokec8 400FF100\cf4 \strokec4 ))\cb1 \
\
\cf2 \cb3 \strokec2 typedef\cf4 \strokec4  \cf2 \strokec2 struct\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3         \{\cb1 \
\cb3         \cf2 \strokec2 uint32_t\cf4 \strokec4  PDOR;\cb1 \
\cb3         \cf2 \strokec2 uint32_t\cf4 \strokec4  PSOR;\cb1 \
\cb3         \cf2 \strokec2 uint32_t\cf4 \strokec4  PCOR;\cb1 \
\cb3         \cf2 \strokec2 uint32_t\cf4 \strokec4  PTOR;\cb1 \
\cb3         \cf2 \strokec2 uint32_t\cf4 \strokec4  PDIR;\cb1 \
\cb3         \cf2 \strokec2 uint32_t\cf4 \strokec4  PDDR;\cb1 \
\cb3         \} GPIO_t;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 GPIO_B\cf4 \strokec4  ((GPIO_t\cf7 \strokec7 *\cf4 \strokec4 )GPIO_B_BASE_ADDR)\cb1 \
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf6 \strokec6 GPIO_E\cf4 \strokec4  ((GPIO_t\cf7 \strokec7 *\cf4 \strokec4 )GPIO_E_BASE_ADDR)\cb1 \
\
\cf2 \cb3 \strokec2 int\cf4 \strokec4  \cf6 \strokec6 main\cf4 \strokec4  (\cf2 \strokec2 void\cf4 \strokec4 )\{\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     SIM_5 \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00002400\cf4 \strokec4 ;\cf9 \strokec9  // este es para el B\cf4 \cb1 \strokec4 \
\
\cb3     PCR_PTB22 \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00000100\cf4 \strokec4 ;\cb1 \
\cb3     PCR_PTB21 \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00000100\cf4 \strokec4 ;\cb1 \
\cb3     PCR_PTE26 \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00000100\cf4 \strokec4 ;\cb1 \
\
\cb3     \cf2 \strokec2 while\cf4 \strokec4  (\cf8 \strokec8 1\cf4 \strokec4 )\{\cb1 \
\
\cb3         \cf10 \strokec10 GPIO_B \cf4 \strokec4 -> \cf10 \strokec10 PDDR\cf4 \strokec4  \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00400000\cf4 \strokec4 ;\cb1 \
\cb3         \cf10 \strokec10 GPIO_B \cf4 \strokec4 -> \cf10 \strokec10 PDOR\cf4 \strokec4  \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00400000\cf4 \strokec4 ;\cf9 \strokec9  //enciende led rojo\cf4 \cb1 \strokec4 \
\
\cb3         \cf10 \strokec10 GPIO_B \cf4 \strokec4 -> \cf10 \strokec10 PDDR\cf4 \strokec4  \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00200000\cf4 \strokec4 ;\cb1 \
\cb3         \cf10 \strokec10 GPIO_B \cf4 \strokec4 -> \cf10 \strokec10 PDOR\cf4 \strokec4  \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 00200000\cf4 \strokec4 ;\cf9 \strokec9  //enciende led azul\cf4 \cb1 \strokec4 \
\
\cb3         \cf10 \strokec10 GPIO_E \cf4 \strokec4 -> \cf10 \strokec10 PDDR\cf4 \strokec4  \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 04000000\cf4 \strokec4 ;\cb1 \
\cb3         \cf10 \strokec10 GPIO_E \cf4 \strokec4 -> \cf10 \strokec10 PDOR\cf4 \strokec4  \cf7 \strokec7 =\cf4 \strokec4  \cf2 \strokec2 0X\cf8 \strokec8 04000000\cf4 \strokec4 ;\cf9 \strokec9  //enciende led verde\cf4 \cb1 \strokec4 \
\
\cb3     \}\cb1 \
\
\cb3     \cf2 \strokec2 return\cf4 \strokec4  \cf8 \strokec8 0\cf4 \strokec4 ;\cb1 \
\cb3 \}\cb1 \
}