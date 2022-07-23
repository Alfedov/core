#include <windows.h>
#include "CChat.h"
#include "kthook.hpp"

using CHud__DrawRadar = void(__cdecl*)(); // Прототип CHud::DrawRadar

kthook::kthook_simple_t<CHud__DrawRadar> samp_init_hook{ reinterpret_cast<void*>(0x58A330) }; // хук на CHud::DrawRadar

void HOOK_after_samp_init() {
    static bool inited = false; // переменная инициализации
    namespace samp = sampapi::v037r2; // Ваша версия сампа, у меня это 037r3
    if (!inited && samp::RefChat() != nullptr) { // если еще не инициализировались, и чат сампа уже инициализировался
        samp::RefChat()->AddMessage(0xFFFFFFFF, "Этот текст выведен после инициализации сампа"); // Выводим сообщение
        samp::RefChat()->m_debugColor = 0xFFFF0000; // Меняем цвет системных сообщений сампа на красный
        inited = true; // отмечаем что иницализировались
    }
}