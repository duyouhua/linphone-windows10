﻿using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;
using System.Windows.Media;

namespace Linphone.Model
{
    /// <summary>
    /// Converter returning the AccentColorBrush if the boolean is true, else returning a title color.
    /// </summary>
    public class MissedToBrushConverter : IValueConverter
    {
        /// <returns>A SolidColorBrush (PhoneAccentBrush or PhoneSubtleBrush).</returns>
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if ((bool)value)
            {
                return (SolidColorBrush)(Application.Current.Resources["PhoneAccentBrush"]);
            }
            else
            {
                return (SolidColorBrush)(Application.Current.Resources["PhoneSubtleBrush"]);
            }
        }

        /// <summary>
        /// Not implemented.
        /// </summary>
        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}