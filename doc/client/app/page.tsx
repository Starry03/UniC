"use client";
import { Input, Typography, Flex, AutoComplete } from "antd";
import { useState } from "react";

export default function Home() {
  const [suggestions, setSuggestions] = useState([]);

  function get_suggestion(input: string) {
    fetch(`http://127.0.0.1:1323/queryFunctions/${input}`, {
      method: "POST",
    })
      .then((response) => response.json())
      .then((data) => {
        setSuggestions(data);
      })
      .catch(() => setSuggestions([]));
  }

  return (
    <Flex vertical>
      <Typography.Title>UniC</Typography.Title>
      <AutoComplete
        options={suggestions?.map(
          (suggestion) => ({
            label: suggestion,
            value: suggestion,
          }),
          // value: suggestion
        )}
        onChange={(value) => get_suggestion(value)}
        placeholder="Search for a function"
      />
    </Flex>
  );
}
