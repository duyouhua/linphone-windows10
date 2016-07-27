/*
VoipCallController.h
Copyright (C) 2015  Belledonne Communications, Grenoble, France
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#pragma once

using namespace Windows::ApplicationModel::Calls;


namespace BelledonneCommunications
{
	namespace Linphone
	{
		namespace Native
		{
			ref class Call;

			[Windows::Foundation::Metadata::WebHostHidden]
			public ref class VoipCallController sealed
			{
			public:
				VoipCallController();
				virtual ~VoipCallController();

				VoipPhoneCall^ NewIncomingCall(Platform::String^ contactUri);
				VoipPhoneCall^ NewOutgoingCall(Platform::String^ contactUri);

			private:
				//Call^ call;
				VoipCallCoordinator^ callCoordinator;
				Platform::String^ voipServiceName;
			};
		}
	}
}
