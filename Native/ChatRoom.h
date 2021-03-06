/*
ChatRoom.h
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

#include "ChatMessage.h"
#include "ChatMessageListener.h"
#include "Core.h"
#include "Enums.h"


namespace BelledonneCommunications
{
	namespace Linphone
	{
		namespace Native
		{
			ref class Address;
			ref class ChatMessage;
			ref class Core;

			/// <summary>
			/// Represents a chat message shared between two users.
			/// </summary>
			public ref class ChatRoom sealed
			{
			public:
				/// <summary>
				/// Gets the list of the messages in the history of this chatroom
				/// </summary>
				property Windows::Foundation::Collections::IVector<ChatMessage^>^ History
				{
					Windows::Foundation::Collections::IVector<ChatMessage^>^ get();
				}

				/// <summary>
				/// Returns the amount of messages associated with the peer of this chatRoom.
				/// </summary>
				property int HistorySize
				{
					int get();
				}

				/// <summary>
				/// Tells whether the remote is currently composing a message.
				/// </summary>
				property Platform::Boolean IsRemoteComposing
				{
					Platform::Boolean get();
				}

				/// <summary>
				/// Returns the Address associated with this ChatRoom.
				/// </summary>
				property Address^ PeerAddress
				{
					Address^ get();
				}

				/// <summary>
				/// Returns the amount of unread messages associated with the peer of this chatRoom.
				/// </summary>
				property int UnreadMessageCount
				{
					int get();
				}

				/// <summary>
				/// Notify the destination of the chat message being composed that the user is typing a new message.
				/// </summary>
				void Compose();

				/// <summary>
				/// Creates a ChatMessage to transfer a file.
				/// </summary>
				/// <param name="type">MIME type of the file to transfer</param>
				/// <param name="subtype">MIME subtype of the file to transfer</param>
				/// <param name="name">Name of the file to transfer</param>
				/// <param name="size">Size in bytes of the file to transfer</param>
				/// <param name="filepath">Path to the file to transfer</param>
				/// <returns>A new ChatMessage</returns>
				ChatMessage^ CreateFileTransferMessage(Platform::String^ type, Platform::String^ subtype, Platform::String^ name, int size, Platform::String^ filepath);

				/// <summary>
				/// Creates a ChatMessage from a String.
				/// </summary>
				ChatMessage^ CreateMessage(Platform::String^ message);

				/// <summary>
				/// Deletes all the messages associated with the peer of this chat room
				/// </summary>
				void DeleteHistory();

				/// <summary>
				/// Deletes a message from the history of the chatroom
				/// </summary>
				void DeleteMessage(ChatMessage^ message);

				/// <summary>
				/// Marks all the messages in this conversation as read
				/// </summary>
				void MarkAsRead();

				/// <summary>
				/// Sends a ChatMessage using the current ChatRoom, and sets the listener to be called when the massge state changes.
				/// </summary>
				void SendMessage(ChatMessage^ message, ChatMessageListener^ listener);

			private:
				friend class Utils;
				friend ref class Core;

				ChatRoom(::LinphoneChatRoom *cr);
				~ChatRoom();

				::LinphoneChatRoom *room;
			};
		}
	}
}