/*
  Copyright (c) 2014, Tolga HOŞGÖR
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef RCC_H_
#define RCC_H_

#include <cstdint>

#include <GPIO.h>
#include <LCD.h>
#include <SYSCFG.h>
#include <TIM.h>

#include <util.h>

namespace stm32f429
{
class RCC
{
public:
  static constexpr std::size_t BaseAddress{ 0x40023800 };

private: //Internal Declarations
  template<std::size_t offset, uint8_t shift, class T, std::size_t regAddress>
  using Module = util::Module<BaseAddress + offset, shift, T, regAddress>;

public: //Declarations
  using GPIOA = Module<0x30, 6, GPIO::Port, GPIO::PortA>;
  using GPIOB = Module<0x30, 6, GPIO::Port, GPIO::PortB>;
  using GPIOC = Module<0x30, 6, GPIO::Port, GPIO::PortC>;
  using GPIOG = Module<0x30, 6, GPIO::Port, GPIO::PortG>;

  using SYSCFG = Module<0x44, 14, stm32f429::SYSCFG, stm32f429::SYSCFG::BaseAddress>;

  using TIM1  = Module<0x44, 0,  TIM::Periph<TIM::_1 >, TIM::_1 >;
  using TIM2  = Module<0x40, 0,  TIM::Periph<TIM::_2 >, TIM::_2 >;
  using TIM3  = Module<0x40, 1,  TIM::Periph<TIM::_3 >, TIM::_3 >;
  using TIM4  = Module<0x40, 2,  TIM::Periph<TIM::_4 >, TIM::_4 >;
  using TIM5  = Module<0x40, 3,  TIM::Periph<TIM::_5 >, TIM::_5 >;
  using TIM6  = Module<0x40, 4,  TIM::Periph<TIM::_6 >, TIM::_6 >;
  using TIM7  = Module<0x40, 5,  TIM::Periph<TIM::_7 >, TIM::_7 >;
  using TIM8  = Module<0x44, 1,  TIM::Periph<TIM::_8 >, TIM::_8 >;
  using TIM9  = Module<0x44, 16, TIM::Periph<TIM::_9 >, TIM::_9 >;
  using TIM10 = Module<0x44, 17, TIM::Periph<TIM::_10>, TIM::_10>;
  using TIM11 = Module<0x44, 18, TIM::Periph<TIM::_11>, TIM::_11>;
  using TIM12 = Module<0x40, 6,  TIM::Periph<TIM::_12>, TIM::_12>;
  using TIM13 = Module<0x40, 7,  TIM::Periph<TIM::_13>, TIM::_13>;
  using TIM14 = Module<0x40, 8,  TIM::Periph<TIM::_14>, TIM::_14>;

  using LCD0 = Module<0x44, 26, LCD::Periph, LCD::_0>;

public: //Methods
  RCC() = delete;

  static constexpr RCC volatile* const instance();

  template<class Module>
  static typename Module::RegType volatile* enablePeriph();

public: //Registers
  uint32_t m_CR; //Clock Control
  uint32_t m_PLLCFGR;
  uint32_t m_CFGR;
  uint32_t m_CIR;
  uint32_t m_AHB1RSTR;
  uint32_t m_AHB2RSTR;
  uint32_t m_AHB3RSTR;
  uint32_t m_reserved1;
  uint32_t m_APB1RSTR;
  uint32_t m_APB2RSTR;
  uint32_t m_reserved2;
  uint32_t m_reserved3;
  uint32_t m_AHB1ENR;
  uint32_t m_AHB2ENR;
  uint32_t m_AHB3ENR;
  uint32_t m_reserved4;
  uint32_t m_APB1ENR;
  uint32_t m_APB2ENR;
  uint32_t m_reserved5;
  uint32_t m_reserved6;
  uint32_t m_AHB1LPENR;
  uint32_t m_AHB2LPENR;
  uint32_t m_AHB3LPENR;
  uint32_t m_reserved7;
  uint32_t m_APB1LPENR;
  uint32_t m_APB2LPENR;
  uint32_t m_reserved8;
  uint32_t m_reserved9;
  uint32_t m_BDCR;
  uint32_t m_CSR;
  uint32_t m_reserved10;
  uint32_t m_reserved11;
  uint32_t m_SSCGR;
  uint32_t m_PLLI2SCFGR;
};

static_assert(sizeof(RCC) == 0x88, "RCC size is wrong. Spec says its 88 bytes long.");

} //NS stm32f429

#include "impl/RCC.impl"

#endif /* RCC_H_ */
