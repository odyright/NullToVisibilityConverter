#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "NullToVisibilityConverter.g.h"

namespace winrt::TD2_WinUI3::implementation
{
    struct NullToVisibilityConverter : NullToVisibilityConverterT<NullToVisibilityConverter>
    {
        NullToVisibilityConverter() = default;

        Microsoft::UI::Xaml::Visibility NullValue() noexcept;
        void NullValue(Microsoft::UI::Xaml::Visibility value) noexcept;

        Microsoft::UI::Xaml::Visibility NonNullValue() noexcept;
        void NonNullValue(Microsoft::UI::Xaml::Visibility value) noexcept;

        Windows::Foundation::IInspectable Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);

        Windows::Foundation::IInspectable ConvertBack(Windows::Foundation::IInspectable const&, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const&, hstring const& language);

    private:
        Microsoft::UI::Xaml::Visibility nullValue = Microsoft::UI::Xaml::Visibility::Collapsed;
        Microsoft::UI::Xaml::Visibility nonNullValue = Microsoft::UI::Xaml::Visibility::Visible;
    };
}

namespace winrt::TD2_WinUI3::factory_implementation
{
    struct NullToVisibilityConverter : NullToVisibilityConverterT<NullToVisibilityConverter, implementation::NullToVisibilityConverter>
    {
    };
}
