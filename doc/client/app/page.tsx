'use client';
import { Input, Typography, Flex } from "antd";
import { useState } from "react";

export default function Home() {
	const [suggestions, setSuggestions] = useState([]);

	function get_suggestion(input: string) {
		fetch(`http://127.0.0.1:1323/queryFunctions/${input}`)
			.then(response => response.json())
			.then(data => {
				console.log(data);
			});
	}

	return (
		<Flex vertical>
			<Typography.Title>UniC</Typography.Title>
			<Input.Search
				placeholder="Function name"
				onSearch={get_suggestion}
			/>
		</Flex>
	);
}
